/**************************************************
 * 
 *  cBuddenbergWilke.cpp
 *  Created on: 14.08.2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#include <iostream>
#include "../mpPhase.h"
#include "pBuddenbergWilke.h"

BuddenbergWilke::BuddenbergWilke (cPhase *p)
: _phase (p)
{
	_components = _phase->getComponents();
	std::cout << "BuddenbergWilke(): Buddenberg-Wilke viscosity mixing rule used.\n";
	std::cout << "              Method is called from phase " << _phase->getName() << "\n";
	std::cout << "              which consists of " << _components.size() << " components.\n";
}

BuddenbergWilke::BuddenbergWilke ()
{
	_phase = nullptr;
}

double BuddenbergWilke::getValue(PropertyType, VariableArray const &vars)
{
	const double phaseDensity = _phase->getValue(PropertyType::density, vars);

	/// \todo: modify this method for arbitrary many components
	const size_t numberOfComponents = 2;

	using array = std::array<double,numberOfComponents>;

	array xn;
	xn[0] = vars[VariableName::xn_WL];
	xn[1] = 1. - xn[0];

	array M;
	double M_mix (0.);
	for (size_t i=0; i<numberOfComponents; ++i)
	{
		M[i] = _components[i]->getMolarMass(); // component molar mass
		M_mix += xn[i]*M[i];  // average molar mass of the entire mixture
	}

	array rho;
	for (size_t i=0; i<numberOfComponents; ++i)
		rho[i] = xn[i]*M[i] / M_mix * phaseDensity; // component partial density

	VariableArray v = vars;
	v[VariableName::rho_WG]= rho[0];
	v[VariableName::rho_CG]= rho[1];

	array eta;
	for (size_t i=0; i<numberOfComponents; ++i)
	eta[i] = _components[i]->getValue(PropertyType::viscosity, v);

	// diffusion coefficient, in this case stored in the 'constantProperties'
	// vector attribute of the cPhase object
	std::array<array, numberOfComponents> D;
	D[0][1] = D[1][0] = _phase->getConstantProperty(0); // in general, D_ij=D_ji

	double eta_mix (0.);
	for (size_t i=0; i<numberOfComponents; ++i)
	{
		double sum (0.);
		for (size_t j=0; j<numberOfComponents; ++j)
		{
			if (j!=i)
			sum += xn[j]/D[i][j];
		}
		eta_mix += eta[i] /	(1+1.385*eta[i]/xn[i]/rho[i] * sum);
	}

	std::cout << "Buddenberg-Wilke returns a mixed viscosity of "
			<< eta_mix << ".\n";

	return eta_mix;
}

