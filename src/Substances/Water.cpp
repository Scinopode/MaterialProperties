/*************************************************
 *
 * cWater.h
 *
 *  Created on: 02.08.2017
 *      Author: Norbert Grunwald
 *
 *************************************************/

#include <iostream>
#include "Water.h"

Water::Water (void)
{
	_name = "Water component";
	_molarMass = 0.01801528; ///< molar mass
	_Tc = 647.096; ///< critical temperature
	_pc = 2.2064e7; ///< critical pressure
	_rhoc = 322.; ///< critical density
	_omega = 0.344; ///< acentric factor
	_Rs = PhysicalConstants::GasConstant / _molarMass;

	_materialConstants[molar_mass] = 0.01801528;
	_materialConstants[specific_gas_constant] = PhysicalConstants::GasConstant
			/ _materialConstants[molar_mass];

	_constantProperties[density] = 1.e3; // kg/m^3
	_constantProperties[viscosity] = 1.e-3; // Pa*s
	_constantProperties[heat_capacity] = 4184.; // J/kg/K
	_constantProperties[thermal_conductivity] = 0.597; // W/m/K


	std::cout << "Water(): Object of class Water created.\n";
}
