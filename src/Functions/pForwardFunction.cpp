/*************************************************
 * 
 *  cForwardFunction.cpp
 *  Created on: Aug 17, 2017
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
#include "pForwardFunction.h"

ForwardFunction::ForwardFunction (cComponent *c)
: _component (c)
{
	std::cout << "ForwardFunction(): ForwardFunction used.\n";
};

ForwardFunction::ForwardFunction ()
{
_component = nullptr;
}

double ForwardFunction::getValue(PropertyType property, VariableArray const &vars)
{
	std::cout << "ForwardFunction calls property " <<
			property << " from component " << _component->getName() << "\n";
	return _component->getValue(property, vars);
}
