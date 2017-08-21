/*************************************************
 *  cComponent.cppFunction.cpp
 *  Created on: Aug 01, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#include "Functions/Functions.h"
#include "mpComponent.h"

void cComponent::setName (std::string s)
{
	this->_name = s;
}

std::string cComponent::getName (void)
{
	return this->_name;
}

double cComponent::getValue (PropertyType property,
		VariableArray const &v)
{
	return _functions[property]->getValue(property, v);
}

double cComponent::getValue (PropertyType property)
{
	return _constantProperties[property];
}

double cComponent::getValue (MaterialConstants materialConstant)
{
	return _materialConstants[materialConstant];
}

void cComponent::addFunction (std::string s, PropertyType property)
{
	std::cout << "cComponent::addFunction(): Adding a function to this component: " << this->_name << "\n";
	if (s.find("IAPWS") != std::string::npos)
	{
		this->_functions[property] = new ViscosityWaterIAPWS(this);
		return;
	}
	if (s.find("Fenghour") && s.find("CO2") != std::string::npos)
	{
		this->_functions[property] = new ViscosityCO2Fenghour(this);
		return;
	}
	if (s.find("constant") != std::string::npos)
	{
		this->_functions[property] = new ConstantValue(this);
		return;
	}
	if (s.find("BilinearJT") != std::string::npos)
	{
		this->_functions[property] = new BilinearJT(this);
		return;
	}
	std::cout << "Warning: Function " << s << " was not recognized.\n";
}

void cComponent::addConstantProperty (PropertyType property, const double value)
{
	this->_constantProperties[property] = value;
}

void cComponent::addMaterialConstant (MaterialConstants property, const double value)
{
	this->_materialConstants[property] = value;
}
