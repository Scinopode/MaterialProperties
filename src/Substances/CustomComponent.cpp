/*************************************************
 * 
 *  cCustomComponent.cpp
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
#include "CustomComponent.h"

CustomComponent::CustomComponent (void)
{
	_name = "custom component";

	_constantProperties[density] = 1.e3; // kg/m^3
	_constantProperties[viscosity] = 1.e-3; // Pa*s
	_constantProperties[heat_capacity] = 4184.; // J/kg/K
	_constantProperties[thermal_conductivity] = 0.597; // W/m/K

	std::cout << "CustomComponent(): Object of class cCustomComponent.\n";

}
