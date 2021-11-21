#include "DynamicSystem.h"


double rad_to_deg(double x) {

	double t = (x * 180 / 3.14159562) - int(x * 180 / 3.14159562);
	return int(x * 180 / 3.14159562) % 360 + t;

}

double radian(double radian) {

	const double pi = 3.14159265;
	while (radian - pi/2 > 0) {

		radian -= pi;

	}
	return radian;

}


double AB(std::vector<double> x) {

	double under_square = ((d1 + L1 * x[0] / 2) * (d1 + L1 * x[0] / 2) + \
		(L1 / 2 - L1 / 2) * (L1 / 2 - L1 / 2));
	return pow(under_square, 0.5);

}


double T1T2(std::vector<double> x) {

	double under_square = (d2 + L2 * x[1] - L1 * x[0]) * (d2 + L2 * x[1] - L1 * x[0]);
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

	double nom = (d2 + L2 * x[1] - L1 * x[0]) * (-L1 * x[0]);
	double denom = L1 * T1T2(x);
	return nom / denom;

}


double deg_T1T2P(std::vector<double> x) {

	double nom = (-d2 - L2 * x[1] + L1 * x[0]) * (-L2 * x[1]);
	double denom = L2 * T1T2(x);
	return nom / denom;

}


double deg_OAB(std::vector<double> x) {

	double nom = (d1 + L1 * x[0] / 2) * (L1 * x[0] / 2);
	double denom = AB(x) * L1 / 2;
	return nom / denom;

}


double _f(std::vector<double> x) {

	return F_el2(x) * L1 * deg_0T1T2(x) + F_el1(x) * L1 / 2 * deg_OAB(x) -
		F_g1() * L1 / 2 * x[0];

}


double _s(std::vector<double> x) {

	return F_el2(x) * L2 * deg_T1T2P(x) - F_g2() * L2 / 2 * x[1];

}


double first(std::vector<double> var) {

	return _f({var[5], var[7]}) / J1;

}
	

double second(std::vector<double> var) {

	return var[4];

}


double third(std::vector<double> var) {

	return _s({ var[5], var[7] }) / J2;

}


double fourth(std::vector<double> var) {

	return var[6];

}

void callback(std::vector<double> x) {

	std::cout << std::endl;
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
	std::cout << "Сумма моментов = " << _f(x) << std::endl;

	std::cout << std::endl;
	std::cout << "Второе тело :" << std::endl;
	std::cout << "M_упр_22 = " << F_el2(x) * L2 * sin(3.14159562 - deg_T1T2P(x)) << std::endl;
	std::cout << "M_т2 = " << -F_g2() * L2 / 2 * sin(x[1]) << std::endl;
	std::cout << "Сумма моментов = " << _s(x) << std::endl;
	std::cout << std::endl;

}
