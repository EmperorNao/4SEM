#include "StaticSystem.h"


StaticSystem::StaticSystem(std::vector<RealFunction> sys_equations) : equations(sys_equations) {

}


StaticSystem::StaticSystem() {

	equations.resize(2);
	std::string t = "((2 * g * u * cos( x - z) + 2 * (g * g + u * u + g * u) + f * f - 2 * \
(f * (g * sin(x) + u * sin(z)) + (g + u) * (g * cos(x) + u * sin(z)))) ^ 0.5 - e)";
	RealFunction delta_2(t);
	std::string first = "2 * b * ((2 * g * u * cos( x - z) + 2 * (g * g + u * u + g * u) + f * f - 2 * \
(f * (g * sin(x) + u * sin(z)) + (g + u) * (g * cos(x) + u * sin(z)))) ^ 0.5 - e) * cos(z) - d * 9.82";
	RealFunction f(first);
	std::string cos_phi_o = "((g * tg(x) / 2 +  e) * (g * tg(x) / 2 +  e) + (g * g / 2 * (1 - cos(x)) + \
e * (e + g * sin(x)) - (g * g / 2 * ((2 + tg(x) * tg(x)) / 2 - (cos(x) + tg(x) * sin(x) ) )  ) ) / (2 * \
(g * tg(x) / 2 +  e) * ((g * g / 2 * (1 - cos(x)) + e * (e + g * sin(x))) ^ 0.5))";
	std::string second = "b * ((2 * g * u * cos( x - z) + 2 * (g * g + u * u + g * u) + f * f - 2 * (f * \
(g * sin(x) + u * sin(z)) + (g + u) * (g * cos(x) + u * sin(z)))) ^ 0.5 - e) * sin(z) - a * ((g * tg(x) /\
 2 +  e) * (g * tg(x) / 2 +  e) + (g * g / 2 * (1 - cos(x)) + e * (e + g * sin(x)) - (g * g / 2 * ((2 + tg(x)\
 * tg(x)) / 2 - (cos(x) + tg(x) * sin(x) ) )  ) ) / (2 * (g * tg(x) / 2 +  e) * ((g * g / 2 * (1 - cos(x)) + e\
 * (e + g * sin(x))) ^ 0.5)) * ((g * g / 2 * (1 - cos(x)) + e * (e + g * sin(x))) ^ 0.5 - f)";
	RealFunction s(second);
	equations[0] = f;
	equations[1] = s;

}


std::string StaticSystem::get_variables_names() {
	
	return equations[0].get_variables();

}


degrees_of_freedom StaticSystem::simulate(system_parameters& param) {

	std::string variables_names;
	std::vector<double> values;
	for (int i = 0; i < param.size(); ++i) {

		variables_names.push_back(param[i].name);
		values.push_back(param[i].value);

	}

	for (int i = 0; i < equations.size(); ++i) {

		equations[i].set_variables_in_formula(variables_names, values);

	}

	int number_of_variables = equations[1].get_variables().size();

	auto solution = solve_nonlinear_system(equations, {0.5, 0.5}, 10e-1);

	if (solution.first) {

		degrees_of_freedom sol(number_of_variables);
		for (int i = 0; i < number_of_variables; ++i) {

			sol[i].value = solution.second[i];

		}
		return sol;

	}
	else {

		return  { };

	}

}
