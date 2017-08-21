/*************************************************
 * 
 * cCustomComponent.h
 *
 *  Created on: Aug 14, 2017
 *  Author: Norbert Grunwald        
 *
 *************************************************/
#ifndef SUBSTANCES_CUSTOMCOMPONENT_H_
#define SUBSTANCES_CUSTOMCOMPONENT_H_

#include "../mpComponent.h"

class CustomComponent final : public cComponent
{
private:

public:
//	virtual double getValue (PropertyType property,
//			VariableArray const &v) override {return 0.;}
	CustomComponent (void);
	CustomComponent (std::string s);
};

#endif /* SUBSTANCES_CUSTOMCOMPONENT_H_ */
