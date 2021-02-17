#include "StaticSystem.h"


StaticSystem::StaticSystem(std::vector<RealFunction> sys_equations) : equations(sys_equations) {

}


StaticSystem::StaticSystem() {

	equations.resize(2);

	std::string t1t2 = "( 2 * (a * a + a * b + b * b) + d * d - 2 * ( ( a * sin( x ) + b * sin( y ) )\
 * d - ( a * cos( x ) + b * cos( y ) ) * ( a + b ) ) ) ^ 0.5";

	std::string ab = "( 0.5 * a * a * ( 1 - cos( x ) ) + c * c + c * a * sin( x ) ) ^ 0.5";

	std::string deg_t1t2p = "acs( ( ( d + b * sin( y ) - a * sin(x) ) * b * sin( y ) + (b * cos( y ) + a\
 * cos( x ) - (a + b) ) * ( b * cos( y ) ) ) / ( b * " + t1t2 +  " ) )";
	
	std::string deg_ot1t2 = "acs( ( ( d + b * sin( y ) - a * sin( x ) ) * ( ( 0 - a ) * sin( x )) + (a + b - (\
 b * cos( y ) + a * cos( x ) ) ) * ( a * cos( x ) ) ) / ( a * " + t1t2 + " ) )";

	std::string deg_oab = "acs( ( ( c + 0.5 * a * sin( x ) ) * ( 0.5 * sin( x ) * a ) + (a * cos( x ) * 0.5\
 - 0.5 * a ) * ( 0.5 * a * cos( x ) ) ) / ( 0.5 * a * " + ab + " ) )";


	std::string first = "h * ( " + t1t2 + " - d ) * sin( 3.14159562 - " + deg_ot1t2 + " ) + 0.5 * \
g * ( " + ab + " - c ) * sin( " + deg_oab + " ) - 0.5 * e * 9.82 * sin( x ) "; 

	std::string second = "h * (" + t1t2 + " - d ) * sin( 3.14159562 - " + deg_t1t2p  + ") - 0.5 * f\
 * 9.82 * sin( y )";

	RealFunction f(first);
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

	auto solution = solve_nonlinear_system(equations, {0.8, 0.8}, 10e-1);

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
