/**************************************************
 * 
 *  cBuddenbergWilke.h
 *  Created on: 14.08.2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#ifndef FUNCTIONS_PBUDDENBERGWILKE_H_
#define FUNCTIONS_PBUDDENBERGWILKE_H_

#include "../mpFunction.h"
#include "../mpComponent.h"

class cPhase; // forward declaration of cPhase;

// EOS specifically made for two component systems
class BuddenbergWilke final : public cFunction
{
private:
	ComponentVector _components;
	cPhase* _phase;

public:

	BuddenbergWilke (cPhase *p);
	BuddenbergWilke ();
	virtual ~BuddenbergWilke () {};
	virtual double getValue (PropertyType, VariableArray const &) override;

};



#endif /* FUNCTIONS_PBUDDENBERGWILKE_H_ */
