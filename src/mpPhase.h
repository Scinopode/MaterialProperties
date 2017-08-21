/*************************************************
 * 
 * cFluid.h
 *
 *  Created on: 08.08.2017
 *      Author: Norbert Grunwald
 *
 *************************************************/
#define debug

#ifndef MPPHASE_H_
#define MPPHASE_H_

#include "Substances/Substances.h"
#include "Functions/Functions.h"
#include "mpComponent.h"
#include "mpEnums.h"
#include "mpFunction.h"

class cPhase
{
protected:
	std::string _name;
	PhaseType _phaseType;   ///< not sure if an attribute 'PhaseType' necessary
//	std::vector<double> _constantProperties; // e.g. interaction coefficients etc.
	MaterialConstantsArray _materialConstants;
	PropertyValues _constantProperties;
	ComponentVector _components;
	PropertyFunctions _functions;

public:
	cPhase (void);
	void addComponent (std::string);
	void addComponent (cComponent*);
	void addConstantProperty (PropertyType, const double);
	void addMaterialConstant (MaterialConstants, const double);

	void addFunction (PropertyType, std::string);
	void addFunctionToLastComponent(PropertyType, std::string);
	void addFunctionToComponent(PropertyType, std::string, size_t);
	void addConstantPropertyToLastComponent(PropertyType, const double);
	void addConstantPropertyToComponent(PropertyType, const double, size_t);
	void addMaterialConstantToLastComponent(MaterialConstants, const double);
	void addMaterialConstantToComponent(MaterialConstants, const double, size_t);


	double getValue (PropertyType, VariableArray const &);

	std::string getName (void) {return _name;}
	ComponentVector getComponents (void) {return _components;}
	std::vector<double> getConstantProperties (void);
	double getConstantProperty (size_t);
	cFunction* getFunction (PropertyType p) { return _functions[p];}

};


#endif /* MPPHASE_H_ */
