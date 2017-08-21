/*************************************************
 *  cBilinear_detF_T.h
 *  Created on: Aug 18, 2017
 *            _   _  _____
 *  Author:  | \ | ||  __ \
 *  Norbert  |  \| || |  \/
 *  Grunwald | . ` || | __
 *           | |\  || |_\ \_
 *           \_| \_(_)____(_)
 *
 *************************************************/
#ifndef FUNCTIONS_CBILINEAR_DETF_T_H_
#define FUNCTIONS_CBILINEAR_DETF_T_H_

#include "../mpComponent.h"
#include "../mpFunction.h"

class BilinearJT final : public cFunction
{
private:
	cComponent* _component;

public:

	BilinearJT (cComponent *c);
	virtual ~BilinearJT () {};
	virtual double getValue (PropertyType, VariableArray const &) override;

};



#endif /* FUNCTIONS_CBILINEAR_DETF_T_H_ */
