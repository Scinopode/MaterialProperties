/**************************************************
 * 
 *  cIdealGasLawDalton.h,
 *  Created on: Aug 11, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/

#ifndef FUNCTIONS_PIDEALGASLAWDALTON_H_
#define FUNCTIONS_PIDEALGASLAWDALTON_H_

#include "../mpFunction.h"
#include "../mpComponent.h"

class IdealGasLawDalton final : public cFunction
{
private:
	ComponentVector _components;
public:

	IdealGasLawDalton (ComponentVector);
	virtual ~IdealGasLawDalton() {};
	virtual double getValue (PropertyType, VariableArray const &) override;

};

#endif /* FUNCTIONS_PIDEALGASLAWDALTON_H_ */
