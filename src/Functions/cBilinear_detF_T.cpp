/*************************************************
 *  cBilinear_detF_T.cpp
 *  Created on: Aug 18, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#include "cBilinear_detF_T.h"
#include <iostream>

BilinearJT::BilinearJT(cComponent *c)
: _component (c)
{
	std::cout << "BilinearJT(): Bi-Linear correlation (det F and T)"
			" for density used.\n";
}

double BilinearJT::getValue(PropertyType property, VariableArray const &v)
{

	const double rho_ref = _component->getValue(reference_density);
	const double T_ref = _component->getValue(reference_temperature);
	const double drhodJ = _component->getValue(drho_by_dJ);
	const double drhodT = _component->getValue(drho_by_dJ);

	const double density = rho_ref + drhodJ * (v[detF] - 1)
			+ drhodT * (v[T] -  T_ref);

	std::cout << "BiLinearJT returns "
			<< density << "\n";

	return density;
}


