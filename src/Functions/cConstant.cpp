/*************************************************
 * 
 *  cConstant.cpp
 *  Created on: Aug 17, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#include "cConstant.h"
#include <iostream>

ConstantValue::ConstantValue(cComponent *c)
: _component (c)
{
	std::cout << "ConstantValue(): ConstantValue function used for component "
			<< _component->getName() << ".\n";
}

double ConstantValue::getValue(PropertyType property, VariableArray const &v)
{
	const double value = _component->getValue(property);
	std::cout << "ConstantValue returns a value of "
			<< value << " for property " << property << "\n";
	return value;
}
