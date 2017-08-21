/*************************************************
 * 
 * cPengRobinson.cpp                         
 *                                      
 *  Created on: 08.08.2017                 #include "../cFunction.h"
 *
 *      Author: Norbert Grunwald        
 *
 *************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
#include "../Math/poly34.h"
#include "pPengRobinsonBinary.h"


PengRobinsonBinary::PengRobinsonBinary (ComponentVector c)
: _components (c)
{
//	_components = components;
	const int componentNumber = _components.size();

	//this->a = 0.4; // todo
	//this->b = 0.07;  // todo

	std::cout << "PengRobinsonBinary(): New function object of type cPengRobinson created.\n";
	std::cout << "                      This object knows " << componentNumber << " components:\n";
	for (auto c : _components)
	{
		std::cout << "                  " << c->getName() << "\n";
	}
};

double cohesionPressure (cComponent *c)
{
	const double Tc = c->getCriticalTemperature();
	const double pc = c->getCriticalPressure();
	const double R = PhysicalConstants::GasConstant;
	return 0.45723553*R*R*Tc*Tc/pc;
}

double coVolume (cComponent *c)
{
	const double Tc = c->getCriticalTemperature();
	const double pc = c->getCriticalPressure();
	const double R = PhysicalConstants::GasConstant;
	return 0.077796074*R*Tc/pc;
}

double alpha (const double T, const double Tc, const double omega)
{
	const double m = 0.37464+1.54226*omega-0.26992*omega*omega;
	const double sqrt_Tred = std::sqrt(T/Tc);
	return 1.+m*(1-sqrt_Tred);
}

void mixingRule (double *a, double *b, double *am, double *bm, const double xi, const double k_ij)
{
	const double aij = (1.-k_ij)*std::sqrt(a[0]*a[1]);
	const double xj = 1-xi;

	*am = xi*xi*a[0]+2*xi*xj*aij+xj*xj*a[1];
	*bm = xi*b[0] + xj*b[1];
}

double PengRobinsonBinary::getValue (PropertyType, VariableArray const &vars)
{
//todo: assert (c.size() >= 2)

	const double temperature = vars[VariableName::T]; // temperature
	const double pressure = vars[VariableName::p_G]; // gas pressure
	const double xi = vars[VariableName::xn_WL];

	double a[2], b[2];
	// loop over the first two components (binary mixture)
	for (unsigned i=0; i<2; ++i)
	{
		auto c = _components[i];
		a[i] = cohesionPressure(c)*
			alpha(temperature, c->getCriticalTemperature(), c->getAcentricFactor());
		b[i] = coVolume(c);
	}

	double am, bm; // Mixed parameters of the composition;
	mixingRule(a,b,&am,&bm,xi,0.);

	const double RT = PhysicalConstants::GasConstant*temperature;

	const double A = am*pressure/RT/RT;
	const double B = bm*pressure/RT;

	// Z^3 + p*Z^2 + q*Z + r = 0
	const double p = B - 1.;
	const double q = A - 3.*B*B - 2.*B;
	const double r = B*B*B + B*B - A*B;

	std::array<double, 3> roots;

	const int numberRoots = SolveP3(roots.data(), p, q, r);

	std::cout << roots[0] << " " << roots[1] << " " << roots[2] << "\n";

	const double Z = (numberRoots > 1 ? *std::max_element(std::begin(roots), std::end(roots)) : roots[0]);
	const double M = xi*_components[1]->getMolarMass()
			+(1-xi)*_components[0]->getMolarMass();

	const double rho = M*pressure/Z/PhysicalConstants::GasConstant/temperature;
	std::cout << "PengRobinson: Density = " << rho << ".\n";
	return rho;
};
