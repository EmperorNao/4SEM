#pragma once
#include "DifferencialEquations.h"
#include "Function.h"
#include <chrono>
#include <thread>
#include <fstream>


const double k1 = 150000;
const double k2 = 20000;
const double m1 = 5;
const double m2 = 7;
const double L1 = 1;
const double L2 = 1;
const double d1 = 0.5;
const double d2 = 1;
const double P = 10;
const double g = 9.82;
const double J1 = m1 * L1 * L1 / 3;
const double J2 = m2 * L2 * L2 / 3 * 10;


const double INFINITE = DBL_MAX;
const int standart_sleep = 5;


double rad_to_deg(double x);
double radian(double radian);


double AB(std::vector<double> x);
double T1T2(std::vector<double> x);
double delta_2(std::vector<double> x);
double delta_1(std::vector<double> x);
double F_el1(std::vector<double> x);
double F_el2(std::vector<double> x);
double F_g1();
double F_g2();
double deg_0T1T2(std::vector<double> x);
double deg_T1T2P(std::vector<double> x);
double deg_OAB(std::vector<double> x);
double _f(std::vector<double> x);
double _s(std::vector<double> x);
double first(std::vector<double> var);
double second(std::vector<double> var);
double third(std::vector<double> var);
double fourth(std::vector<double> var);
void callback(std::vector<double> x);


class DynamicSystem {

private:

	int number_of_variables = 4;
	std::vector<RealFunction> system;
	std::vector<double> start_x;
	std::vector<double> start_y;
	
public:

	DynamicSystem(std::vector<double> x_0, std::vector<double> y_0) {

		system = { RealFunction(first), RealFunction(second), RealFunction(third), RealFunction(fourth) };
		start_x = x_0;
		start_y = y_0;

	}


	void simulate(double end = INFINITE, double step = 0.1, int sleep = standart_sleep) {

		double precision = 10e-3;
		std::ofstream os("file.txt");
		std::cout << "Начальные условия: " << std::endl;
		std::cout << "t = " << start_x[0] << ", w_1 = " << start_y[0] << std::endl;
		std::cout << "t = " << start_x[1] << ", phi_1 = " << rad_to_deg(start_y[1]) << std::endl;
		std::cout << "t = " << start_x[2] << ", w_2 = " << start_y[2] << std::endl;
		std::cout << "t = " << start_x[3] << ", phi_2 = " << rad_to_deg(start_y[3]) << std::endl << std::endl;
		double t = 0;
		while (t < end) {
			
			auto solution = solve_system_by_runge_kutta_method(system, start_x, start_y, std::vector<double>(system.size(), t), precision);
			double phi_1 = solution[1].value;
			double phi_2 = solution[3].value;

			//std::cout << "В момент времени t = " << t << " имеем: " << std::endl;
			//callback({ phi_1, phi_2 });
			//std::cout << t;
			std::cout << t << ";" << radian(phi_1) << ";" << radian(phi_2) << std::endl;
			t += step;

			std::this_thread::sleep_for(std::chrono::seconds(sleep));

		}


	}


};

