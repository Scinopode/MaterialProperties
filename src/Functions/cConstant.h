/*************************************************
 * 
 *  cConstant.h
 *  Created on: Aug 17, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#ifndef FUNCTIONS_CCONSTANT_H_
#define FUNCTIONS_CCONSTANT_H_

#include "../mpComponent.h"
#include "../mpFunction.h"

class cPhase; // forward declaration of cPhase;

class ConstantValue final : public cFunction
{
private:
	cComponent* _component;

public:

	ConstantValue (cComponent *c);
	virtual ~ConstantValue () {};
	virtual double getValue (PropertyType, VariableArray const &) override;

};



#endif /* FUNCTIONS_CCONSTANT_H_ */
