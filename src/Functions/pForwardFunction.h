/*************************************************
 * 
 *  cForwardFunction.h
 *  Created on: Aug 17, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/
#ifndef FUNCTIONS_PFORWARDFUNCTION_H_
#define FUNCTIONS_PFORWARDFUNCTION_H_

#include "../mpComponent.h"
#include "../mpFunction.h"

class cPhase; // forward declaration of cPhase;


class ForwardFunction final : public cFunction
{
private:
	cComponent* _component;

public:

	ForwardFunction (cComponent*);
	ForwardFunction ();
	virtual ~ForwardFunction () {};
	virtual double getValue (PropertyType, VariableArray const &) override;

};

#endif /* FUNCTIONS_PFORWARDFUNCTION_H_ */
