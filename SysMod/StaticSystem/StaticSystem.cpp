#include "StaticSystem.h"


StaticSystem::StaticSystem(std::vector<RealFunction> sys_equations) : equations(sys_equations) {

}


double rad_to_deg(double x) {

	double t = (x * 180 / 3.14159562) - int(x * 180 / 3.14159562);
	return int(x * 180 / 3.14159562) % 360 + t;

}


double AB(std::vector<double> x) {

	double under_square = ((d1 + L1 * sin(x[0]) / 2) * (d1 + L1 * sin(x[0]) / 2) + \
		(L1 / 2 - L1 / 2 * cos(x[0])) * (L1 / 2 - L1 / 2 * cos(x[0])));
	return pow(under_square, 0.5);

}


double T1T2(std::vector<double> x) {

	double under_square = (d2 + L2 * sin(x[1]) - L1 * sin(x[0])) * (d2 + L2 * sin(x[1]) - L1 * sin(x[0])) + \
		(L2 + L1 - L2 * cos(x[1]) - L1 * cos(x[0])) * (L2 + L1 - L2 * cos(x[1]) - L1 * cos(x[0]));
	return pow(under_square, 0.5); 

}


double delta_2(std::vector<double> x) {

	return T1T2(x) - d2;

}


double delta_1(std::vector<double> x) {

	return AB(x) - d1;

}


double F_el1(std::vector<double> x) {

	return k1 * delta_1(x);

}


double F_el2(std::vector<double> x) {

	return k2 * delta_2(x);
	
}


double F_g1() {

	return m1 * g;

}


double F_g2() {

	return m2 * g;

}


double deg_0T1T2(std::vector<double> x) {

	double nom = (d2 + L2 * sin(x[1]) - L1 * sin(x[0])) * ( - L1 * sin(x[0])) + \
		(L2 + L1 - L2 * cos(x[1]) - L1 * cos(x[0])) * ( - L1 * cos(x[0]));
	double denom = L1 * T1T2(x);
	return nom / denom;

}


double deg_T1T2P(std::vector<double> x) {

	double nom = (-d2 - L2 * sin(x[1]) + L1 * sin(x[0])) * (-L2 * sin(x[1])) + \
		(-L2 - L1 + L2 * cos(x[1]) + L1 * cos(x[0])) * (L2 * cos(x[1]));
	double denom = L2 * T1T2(x);
	return nom / denom;

}


double deg_OAB(std::vector<double> x) {

	double nom = (d1 + L1 * sin(x[0]) / 2) * (L1 * sin(x[0]) / 2) + \
		(L1 * cos(x[0]) / 2 - L1 / 2) * (L1 * cos(x[0]));
	double denom = AB(x) * L1 / 2;
	return nom / denom;

}


double _f(std::vector<double> x) {

	return F_el2(x) * L1 * sin(3.14159562 - deg_0T1T2(x)) + F_el1(x) * L1 / 2 * sin(deg_OAB(x)) -
		F_g1() * L1 / 2 * sin(x[0]) - P * L1;

}


double _s(std::vector<double> x) {

	return F_el2(x) * L2 * sin(3.14159562 - deg_T1T2P(x)) - F_g2() * L2 / 2 * sin(x[1]);

}


void callback(std::vector<double> x) {

	std::cout << std::endl;
	std::cout << "Был вызван колбек" << std::endl << std::endl;

	std::cout << "phi_1 = " << rad_to_deg(x[0]) << std::endl;
	std::cout << "phi_2 = " << rad_to_deg(x[1]) << std::endl;

	std::cout << "F_упр_1 = " << F_el1(x) << std::endl;
	std::cout << "F_упр_2 = " << F_el2(x) << std::endl;

	std::cout << "F_т_1 = " << F_g1() << std::endl;
	std::cout << "F_т_2 = " << F_g2() << std::endl << std::endl;

	std::cout << "Первое тело :" << std::endl;
	std::cout << "M_упр_1 = " << F_el1(x) * L1 / 2 * sin(deg_OAB(x)) << std::endl;
	std::cout << "M_упр_21 = " << F_el2(x) * L1 * sin(3.14159562 - deg_0T1T2(x)) << std::endl;
	std::cout << "M_т1 = " << -F_g1() * L1 / 2 * sin(x[0]) << std::endl;
	std::cout << "M_P = " << -P * L1 << std::endl;
	std::cout << "Сумма моментов = " << _f(x) << std::endl;

	std::cout << std::endl;
	std::cout << "Второе тело :" << std::endl;
	std::cout << "M_упр_22 = " << F_el2(x) * L2 * sin(3.14159562 - deg_T1T2P(x)) << std::endl;
	std::cout << "M_т2 = " << -F_g2() * L2 / 2 * sin(x[1]) << std::endl;
	std::cout << "Сумма моментов = " << _s(x) << std::endl;
	std::cout << std::endl;


}

StaticSystem::StaticSystem() {

	equations.resize(2);

	std::string t1t2 = "( ( 2 * (a * a + a * b + b * b) + d * d - 2 * ( ( a * sin( x ) + b * sin( y ) )\
 * d - ( a * cos( x ) + b * cos( y ) ) * ( a + b ) ) ) ^ 0.5 ) ";

	std::string ab = "( 0.5 * a * a * ( 1 - cos( x ) ) + c * c + c * a * sin( x ) ) ^ 0.5";

	std::string deg_t1t2p = "acs( ( ( d + b * sin( y ) - a * sin(x) ) * b * sin( y ) + ( b * cos( y ) + a\
 * cos( x ) - (a + b) ) * ( b * cos( y ) ) ) / ( b * " + t1t2 +  " ) )";
	
	std::string deg_ot1t2 = "acs( ( ( d + b * sin( y ) - a * sin( x ) ) * ( ( 0 - a ) * sin( x )) + (a + b - (\
 b * cos( y ) + a * cos( x ) ) ) * ( a * cos( x ) ) ) / ( a * " + t1t2 + " ) )";

	std::string deg_oab = "acs( ( ( c + 0.5 * a * sin( x ) ) * ( 0.5 * sin( x ) * a ) + (a * cos( x ) * 0.5\
 - 0.5 * a ) * ( 0.5 * a * cos( x ) ) ) / ( 0.5 * a * " + ab + " ) )";


	std::string first = "h * ( " + t1t2 + " - d ) * sin( 3.14159562 - " + deg_ot1t2 + " ) + 0.5 * \
g * ( " + ab + " - c ) * sin( " + deg_oab + " ) - 0.5 * e * 9.82 * sin( x ) - t "; 

	std::string second = "h * ( " + t1t2 + " - d ) * sin( 3.14159562 - " + deg_t1t2p  + ") - 0.5 * f\
 * 9.82 * sin( y )";

	RealFunction f(_s);
	RealFunction s(_f);
	equations[0] = f;
	equations[1] = s;

}


std::string StaticSystem::get_variables_names() {
	
	return equations[0].get_variables();

}


std::vector<double> StaticSystem::simulate() {

	std::vector<double> start_solution = { 0.4, 0.4 };
	double precision = 10e-6;
	auto solution = solve_nonlinear_system(equations, start_solution, precision, 5000, callback);

	std::vector<double> sol(number_of_variables);
	if (solution.first) {

		for (int i = 0; i < number_of_variables; ++i) {

			sol[i] = solution.second[i];

		}
		return sol;

	}
	else {

		return  { };

	}

}
