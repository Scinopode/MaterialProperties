/*************************************************
 *
 * cCarbonDioxide.cpp
 *
 *  Created on: 02.08.2017
 *      Author: Norbert Grunwald
 *
 *************************************************/

#include <iostream>
#include "CarbonDioxide.h"

CarbonDioxide::CarbonDioxide ()
{
	_molarMass = .044001;
	_Tc = 304.1282;
	_epsilon_k = 251.196;

	this->setName("Carbon Dioxide component");

	this->setCriticalPressure(7.375e6);
	this->setAcentricFactor(0.239);

	std::cout << "CarbonDioxide(): Object of class CarbonDioxide created.\n";

}
