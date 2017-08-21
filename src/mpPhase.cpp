/*************************************************
 * 
 *  mpPhase.cpp
 *  Created on: 08.08.2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#include <iostream>
#include "mpPhase.h"

void cPhase::addComponent(std::string s)
{
	if (s == "Water" || s== "H2O")
	{ _components.push_back(new Water); return; }
	if (s == "CarbonDioxide" || s == "CO2")
	{ _components.push_back(new CarbonDioxide); return; }
	if (s == "Salt" || s == "NaCl")
	{ _components.push_back(new CarbonDioxide); return; }
	_components.push_back(new CustomComponent);

}

void cPhase::addComponent(cComponent* component)
{
	_components.push_back(component);
}

void cPhase::addConstantProperty(PropertyType p, const double v)
{
	_constantProperties[p] = v;
}

void cPhase::addMaterialConstant(MaterialConstants m, const double v)
{
	_materialConstants[m] = v;
}

// This method has to be called after adding the component.
// Alternatively, the index of the relevant component could
// be given in the argument list.
void cPhase::addFunctionToLastComponent(PropertyType p, std::string s)
{
	_components.back()->addFunction(s,p);
}
void cPhase::addFunctionToComponent(PropertyType p, std::string s, size_t index)
{
	_components[index]->addFunction(s,p);
}


// This method has to be called after adding the component.
// Alternatively, the index of the relevant component could
// be given in the argument list.
void cPhase::addConstantPropertyToLastComponent(PropertyType p, const double v)
{
	_components.back()->addConstantProperty(p, v);
}
void cPhase::addConstantPropertyToComponent(PropertyType p, const double v,size_t index)
{
	_components[index]->addConstantProperty(p, v);
}


// This method has to be called after adding the component.
// Alternatively, the index of the relevant component could
// be given in the argument list.
void cPhase::addMaterialConstantToLastComponent(MaterialConstants m, const double v)
{
	_components.back()->addMaterialConstant(m, v);
}
void cPhase::addMaterialConstantToComponent(MaterialConstants m, const double v, size_t index)
{
	_components[index]->addMaterialConstant(m, v);
}

void cPhase::addFunction (PropertyType property, std::string s)
{
	if (s=="IdealGasLaw_Dalton" || s=="IGL_dalton")
	{
		this->_functions[property] = new IdealGasLawDalton(this->_components);
		return;
	}
	if (s=="PengRobinsonBinary" || s=="PREOSBinary")
	{
		this->_functions[property] = new PengRobinsonBinary(this->_components);
		return;
	}
	if (s=="BuddenbergWilke" || s=="Buddenberg_Wilke")
	{
		this->_functions[property] = new BuddenbergWilke(this);
		return;
	}
	if (s=="Custom_H2O_CO2_NaCl_EOS")
	{
		this->_functions[property] = new BuddenbergWilke(this);
		return;
	}
	if (s=="Viscosity_brine_CO2")
	{
		this->_functions[property] = new BuddenbergWilke(this);
		return;
	}

	this->_functions[property] = new ForwardFunction(this->_components[0]);
}

double cPhase::getConstantProperty (size_t index)
{
	if (_constantProperties.size() <= index)
	{
		std::cout << "Warning: index out of range in cPhase::getConstantProperties (size_t index). Returning 0.\n";
		return 0.;
	}
	return _constantProperties[index];
}


cPhase::cPhase()
: _name ("default"),
  _phaseType (PhaseType::unknown)
{
	std::cout << "cPhase(): New object of class cPhase created.\n";
	std::cout << _functions.size() << " functions reserved.\n";
}

double cPhase::getValue (PropertyType property, VariableArray const &v)
{
//	if (_components.size() == 1)
//			return this->_components[0]->getValue(property, v);
	return _functions[property]->getValue(property, v);
}


