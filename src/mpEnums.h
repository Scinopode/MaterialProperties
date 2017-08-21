/*************************************************
 * 
 * cEnums.h
 *
 *  Created on: Aug 11, 2017
 *  Author: Norbert Grunwald        
 *
 *************************************************/
#ifndef MPENUMS_H_
#define MPENUMS_H_

#include <array>
#include <vector>

enum PhaseType : std::size_t
{
	solid,
	liquid,
	gas,
	wetting,
	non_wetting,
	unknown,
	number_of_phase_types  // just in case
};

enum MaterialConstants : std::size_t
{
	molar_mass,
	acentric_factor,
	specific_gas_constant,
	critical_pressure,
	critical_temperature,
	critical_density,
	maxcondentherm_pressure,
	maxcondentherm_temperature,
	maxcondentherm_density,
	rererence_pressure,
	reference_temperature,
	reference_density,
	collision_cross_section,
	interaction_parameter,
	epsilon_k,
	drho_by_dJ,
	drho_by_dT,
	number_of_material_constants
};

using MaterialConstantsArray = std::array<double, MaterialConstants::number_of_material_constants>;

enum PropertyType : std::size_t
{
	density,
	viscosity,
	thermal_conductivity,
	heat_capacity,
	effective_stess,
	number_of_property_types
};

template <typename T>
using PropertyArray = std::array<T, PropertyType::number_of_property_types>;

enum VariableName : std::size_t
	{
	p_G, ///< pressure of gas phase
	p_L, ///< pressure of liquid phase
	p_c, ///< capillary pressure
	T_G, ///< gas phase temperature
	T_L, ///< liquid phase temperature
	T_S, ///< solid phase temperature
	T,   ///< local thermal equilibrium temperature
	u_x, ///< displacement x component
	u_y, ///< displacement y component
	u_z, ///< displacement z component
	xn_WL, ///< mole fraction of water in liquid phase
	xn_CG, ///< mole fraction of CO2 in gas phase
	rho_WL, ///< liquid water density
	rho_WG, ///< gas phase water vapour partial density
	rho_CL, ///< aqueous co2 partial density
	rho_CG, ///< gaseous co2 partial density
	detF,   ///< determinant of deformation gradient
	number_of_variable_names
	};

using VariableArray = std::array<double,
		VariableName::number_of_variable_names>;

//using Vector = std::array<double,3>;
//using Tensor = std::array<double,9>;
//using SymmetricTensor = std::array<double,6>;
//using Species = std::vector<std::vector<double> >;
//
////class cPhase;
//
//struct VariableContainer
//{
//	double p_G;  ///< pressure of gas phase
//	double p_L; ///< pressure of liquid phase
//	double p_c; ///< capillary pressure
//	double T_G; ///< gas phase temperature
//	double T_L; ///< liquid phase temperature
//	double T_S; ///< solid phase temperature
//	double T;   ///< local thermal equilibrium temperature
//	Vector u; ///< displacement vector
//	Tensor strain; ///< strain tensor
//	Tensor stress; ///< stress tensor
//	Species xn_alpha_zeta;   ///< mol fraction x_n[phase][component]
//	Species rho_alpha_zeta; ///< density rho [phase][component]
//
////	VariableContainer() {};
//};


#endif /* MPENUMS_H_ */
