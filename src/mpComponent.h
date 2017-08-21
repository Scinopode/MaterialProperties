/*
 * cComponent.h
 *
 *  Created on: 01.08.2017
 *      Author: norbert
 */

#ifndef MPCOMPONENT_H_
#define MPCOMPONENT_H_

#include <vector>
#include <string>

#include "mpEnums.h"
#include "mpFunction.h"

namespace PhysicalConstants
{
	const double GasConstant = 8.314472;
}

/**
 * \brief Base class for component (substance) properties
 */
class cComponent
{
protected:
	std::string _name;

	// Substance physical and chemical properties
	double _molarMass;			// molar mass, kg/mol
	double _Rs;			// specific gas constant
	double _rhoc;   	// kg/m3; critical density
	double _pc;      	// Pa; critical pressure
	double _pj;      	// MPa; Maxcondentherm pressure

	double _Tc;     	// K; critical temperature
	double _Tj;     	// K; Maxcondentherm temperature
	double _rhoj;   	// mol/dm3; Maxcondentherm density
	double _heat_capacity;

	double _rhoref;	// reference density

	double _lowDensity;	// lowest reasonable density in EOS validity range
	double _highDensity;	// highest reasonable density

	double _Tref;		// reference temperature
	double _omega;		// acentric factor
	double _sigma;		// collision cross section (mm^2)

	double _epsilon_k;  // energy scaling parameter, used for some viscosity correlations
	double _drhodJ;		// (constant) derivatives of density at a certain point
	double _drhodT;


	PropertyValues _constantProperties; // Properties that are technically
	// functions, but which are considered to be constant for some
	// materials and/or conditions.
	MaterialConstantsArray _materialConstants; // Measurable Properties
	// that are used to obtain the state of a substance (e.g. molar mass ...)

	PropertyFunctions _functions;


public:

	virtual ~cComponent(void) {};
//	virtual double getValue (PropertyType property,
//			VariableArray const &v) = 0;

	double getValue (PropertyType,	VariableArray const &);
	double getValue (PropertyType);
	double getValue (MaterialConstants);



	void addFunction (std::string s, PropertyType property);
	void addConstantProperty (PropertyType, const double);
	void addMaterialConstant (MaterialConstants, const double);

	void setName (std::string);
	std::string getName (void);

	void setMolarMass (const double M) {_molarMass = M;}
	void setCriticalTemperature (const double Tc) { _Tc = Tc;}
	void setCriticalPressure (const double pc) { _pc = pc;}
	void setAcentricFactor (const double omega) { _omega = omega;}

	double getMolarMass (void) const { return _molarMass;}
	double getCriticalTemperature (void) const { return _Tc;}
	double getCriticalPressure (void) const { return _pc;}
	double getCriticalDensity (void) const { return _rhoc;}
	double getEpsilonK (void) const {return _epsilon_k;}

	double getAcentricFactor (void) const { return _omega;}
	double getdrhodJ (void) const { return _drhodJ;}
	double getdrhodT (void) const { return _drhodT;}



};

using ComponentVector = std::vector<cComponent*>;

#endif /* MPCOMPONENT_H_ */
