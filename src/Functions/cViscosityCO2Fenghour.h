/**************************************************
 * 
 *  cViscosityCO2Fenghour.h
 *  Created on: 15.08.2017
 *             _   _  _____
 *  Author:   | \ | ||  __ \
 *  Norbert   |  \| || |  \/
 *  Grunwald  | . ` || | __
 *            | |\  || |_\ \_
 *            \_| \_(_)____(_)
 *
 *************************************************/
#ifndef FUNCTIONS_CVISCOSITYCO2FENGHOUR_H_
#define FUNCTIONS_CVISCOSITYCO2FENGHOUR_H_

#include "../mpFunction.h"
#include "../mpComponent.h"
#include <iostream>

/* \brief Fenghour, A., Wakeham, A., and Vesovic, V.: The Viscosity of
 *        Carbon Dioxide.J. Phys. Chem. Ref. Data, Vol 27, No. 1, 1998
 */
class ViscosityCO2Fenghour : public cFunction
{
private:
	cComponent* _component;
	std::array<double,5> _a;
	std::array<double,5> _d;

public:
	ViscosityCO2Fenghour (cComponent*);
	virtual double getValue (PropertyType, VariableArray const &) override;
};



#endif /* FUNCTIONS_CVISCOSITYCO2FENGHOUR_H_ */
