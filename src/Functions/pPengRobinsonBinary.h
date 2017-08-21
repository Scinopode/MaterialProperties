/*************************************************
 * 
 * cPengRobinson.h                         
 *                                      
 *  Created on: 08.08.2017                 
 *      Author: Norbert Grunwald        
 *
 *************************************************/

#ifndef FUNCTIONS_PPENGROBINSONBINARY_H_
#define FUNCTIONS_PPENGROBINSONBINARY_H_

#include "../mpFunction.h"
#include "../mpComponent.h"


// EOS specifically made for two component systems
class PengRobinsonBinary final : public cFunction
{
private:
	ComponentVector _components;

public:

	PengRobinsonBinary (ComponentVector components);
	virtual ~PengRobinsonBinary () {};
	virtual double getValue (PropertyType, VariableArray const &) override;

//	double cohesionPressure (cComponent*);
//	double coVolume (cComponent*);

	int compressibilityFactor (const double a, const double b,
			const double c, double *z);

};


#endif /* FUNCTIONS_PPENGROBINSONBINARY_H_ */
