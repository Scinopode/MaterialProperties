/*************************************************
 * 
 * cCarbonDioxide.h
 *
 *  Created on: 02.08.2017
 *      Author: Norbert Grunwald
 *
 *************************************************/

#ifndef SUBSTANCES_CARBONDIOXIDE_H_
#define SUBSTANCES_CARBONDIOXIDE_H_

#include "../mpComponent.h"

class CarbonDioxide final : public cComponent
{
private:
//	const double _pc = 73.e6;
//	const double _PengRobinsonA = 0.45723553 * PhysicalConstantsE::GasConstant * PhysicalConstantsE::GasConstant
//		* _Tc * _Tc / _pc;
//	const double _PengRobinsonB = 0.077796074*PhysicalConstantsE::GasConstant * _Tc / _pc;

public:

//	virtual double getValue (PropertyType property,
//			VariableArray const &v) override;
	const double getPengRobinsonA (void);
	CarbonDioxide (void);
};


#endif /* SUBSTANCES_CARBONDIOXIDE_H_ */
