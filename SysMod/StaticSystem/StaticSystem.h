#pragma once
#include "NonLinearSystemSolver.h"


const double k1 = 15000;
const double k2 = 20000;
const double m1 = 5;
const double m2 = 7;
const double L1 = 1;
const double L2 = 1;
const double d1 = 0.5;
const double d2 = 1;
const double P = 10;
const double g = 9.82;


class StaticSystem {

	private:

		std::vector<RealFunction> equations;
		int number_of_variables = 2;

	public:

		StaticSystem(std::vector<RealFunction> sys_equations);
		StaticSystem();
		std::string get_variables_names();
		std::vector<double> simulate();


};