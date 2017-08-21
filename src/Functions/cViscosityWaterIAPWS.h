/**************************************************
 * 
 *  cViscosityWaterIAPWS.h
 *
 *  Created on: 15.08.2017
 *             _   _  _____
 *  Author:   | \ | ||  __ \
 *  Norbert   |  \| || |  \/
 *  Grunwald  | . ` || | __
 *            | |\  || |_\ \_
 *            \_| \_(_)____(_)
 *
 *************************************************/
#ifndef FUNCTIONS_CVISCOSITYWATERIAPWS_H_
#define FUNCTIONS_CVISCOSITYWATERIAPWS_H_

#include "../mpFunction.h"
#include "../mpComponent.h"
#include <iostream>

/* \brief J.R. Cooper et. al: The International Association for the Properties
 *        of Water and Steam. Berlin, Germany, September 2008.
 */
class ViscosityWaterIAPWS : public cFunction
{
private:
	cComponent* _component;
	std::array<double, 4> _H;
	std::array<std::array<double, 7>, 6> _h;

public:
	ViscosityWaterIAPWS (cComponent*);
	virtual double getValue (PropertyType, VariableArray const &) override;
};



#endif /* FUNCTIONS_CVISCOSITYWATERIAPWS_H_ */
