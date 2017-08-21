/*************************************************
 * 
 * cFunction.h
 *
 *  Created on: 08.08.2017
 *      Author: Norbert Grunwald
 *
 *************************************************/

#ifndef MPFUNCTION_H_
#define MPFUNCTION_H_

#include "mpEnums.h"

class cPhase;

class cFunction
{
protected:
	cPhase* _phase;
public:
	virtual ~cFunction(){};
	virtual double getValue (PropertyType, VariableArray const &);
};

using PropertyFunctions = PropertyArray<cFunction*>;
using PropertyValues = PropertyArray<double>;

#endif /* MPFUNCTION_H_ */
