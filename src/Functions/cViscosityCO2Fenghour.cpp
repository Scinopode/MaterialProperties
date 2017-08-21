/**************************************************
 * 
 *  cViscosityCO2Fenghour.cpp
 *  Created on: 15.08.2017
 *             _   _  _____
 *  Author:   | \ | ||  __ \
 *  Norbert   |  \| || |  \/
 *  Grunwald  | . ` || | __
 *            | |\  || |_\ \_
 *            \_| \_(_)____(_)
 *
 *************************************************/

#include "cViscosityCO2Fenghour.h"
#include <cmath>

ViscosityCO2Fenghour::ViscosityCO2Fenghour(cComponent* c)
: _component (c),
  _a { 0.235156, -0.491266, 0.05211155, 0.05347906, -0.01537102},
  _d {0.4071119e-02, 0.7198037e-04, 0.2411697e-16, 0.2971072e-22, -0.1627888e-22}
{
	std::cout << "ViscosityCO2Fenghour():Fenghour-Wakeham-Vesovic-Correlation for CO2-viscosity used.\n";
}

double ViscosityCO2Fenghour::getValue(PropertyType, VariableArray const &vars)
{
	const double T_red = vars[VariableName::T]/_component->getEpsilonK();
	const double rho = vars[VariableName::rho_CG];

	const double rho_pow_2 = rho*rho;
	const double rho_pow_6 = rho_pow_2 * rho_pow_2 * rho_pow_2;
	const double rho_pow_8 = rho_pow_6 * rho_pow_2;

	double psi (0.);

	for (size_t i=0; i<_a.size(); i++)
		psi += _a[i] * std::pow(std::log(T_red),i);

	const double eta_0 = 1.00697*std::sqrt(T_red)/std::exp(psi);
	const double eta_d = _d[0]*rho + _d[1]*rho_pow_2 + _d[2]*rho_pow_6/T_red
			+ _d[3]*rho_pow_8 + _d[4]*rho_pow_8/T_red;
	const double eta = (eta_0 + eta_d) / 1.e6;

	std::cout << "Fenghour-Wakeham-Vesovic-Correlation  returns "
			"a viscosity of " << eta << "\n";
	return eta;
}

