/**************************************************
 *  cViscosityWaterIAPWS.cpp
 *  Created on: 15.08.2017
 *             _   _  _____
 *  Author:   | \ | ||  __ \
 *  Norbert   |  \| || |  \/
 *  Grunwald  | . ` || | __
 *            | |\  || |_\ \_
 *            \_| \_(_)____(_)
 *
 *************************************************/

#include "cViscosityWaterIAPWS.h"
#include <cmath>

ViscosityWaterIAPWS::ViscosityWaterIAPWS(cComponent *c)
: _component (c),
	_H {{1.67752, 2.20462, 0.6366564,-0.241605}},
	_h {{ { 0.5200940, 0.2225310,-0.2813780, 0.1619130,-0.0325372, 0.,         0.},
          { 0.0850895, 0.9991150,-0.9068510, 0.2573990, 0.,        0.,         0.},
          {-1.0837400, 1.8879700,-0.772479,  0.,        0.,        0.,         0.},
          {-0.289555,  1.266130, -0.489837,  0.,        0.0698452, 0.,        -0.00435673},
          { 0.,        0.,       -0.257040,  0.,        0.,        0.00872102, 0.},
          { 0.,        0.120573,  0.,        0.,        0.,        0.,        -0.000593264}
	}}
{
	std::cout << "ViscosityWaterIAPWS(): IAPWS-Correlation for Water viscosity used.\n";
};

double ViscosityWaterIAPWS::getValue (PropertyType, VariableArray const &vars)
{
		double T_red = vars[VariableName::T]
						/ _component->getCriticalTemperature();
		double rho_red = vars[VariableName::rho_WG]
						/ _component->getCriticalDensity();

		std::array<double,3> sum{ {0.,0.,0.} };

		for(unsigned i=0; i < 4; ++i)
			sum[0] += _H[i] / std::pow(T_red,i);

		for(unsigned i=0; i<6; ++i)
			for (unsigned j=0; j<7; ++j)
			{
				sum[2] += _h[i][j] * std::pow(rho_red - 1.,j);
				sum[1] +=  (std::pow(1. / T_red - 1.,i) * sum[2]);
				sum[2] = 0;
			}

		const double eta = 100. * std::sqrt(T_red) / sum[0]
				* std::exp(rho_red * sum[1]) / 1.e6;

		std::cout << "IAPWS-Correlation returns a viscosity of "
				<< eta << ".\n";
		return eta;
}


