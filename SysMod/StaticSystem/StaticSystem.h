#pragma once
#include "NonLinearSystemSolver.h"


struct parameter {

	char name;
	double value;
	std::string description;

};


typedef std::vector<parameter> system_parameters;

typedef std::vector<parameter> degrees_of_freedom;


// функция симулирует систему с исходными параметрами param,
// возвращая позиции тел после установления равновесия
class StaticSystem {

	private:

		std::vector<RealFunction> equations;

	public:

		StaticSystem(std::vector<RealFunction> sys_equations);
		StaticSystem();
		std::string get_variables_names();
		degrees_of_freedom simulate(system_parameters& param);


};