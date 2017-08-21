/*************************************************
 * 
 * cIdealGasLawDalton.cpp
 *
 *  Created on: Aug 11, 2017
 *  Author: Norbert Grunwald        
 *
 *************************************************/

#include <iostream>
#include "pIdealGasLawDalton.h"

IdealGasLawDalton::IdealGasLawDalton (ComponentVector c)
: _components (c)
{
//	_components = c;
//	components = c;

	std::cout << "IdealGasLawDalton(): New function object of type cIdealGasLawDalton created.\n";
	std::cout << "                     This object knows " << _components.size() << " components:\n";
	for (auto c : _components)
	{
		std::cout << "    " << c->getName() << "\n";
	}
};

double IdealGasLawDalton::getValue (PropertyType, VariableArray const &vars)
{
//	std::cout << this->_components[0]->getMolarMass() << "\n";
//	std::cout << this->components[0]->getMolarMass() << "\n";

	double rho = 0.3;
	return rho;
};
