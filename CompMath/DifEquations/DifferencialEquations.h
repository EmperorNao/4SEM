#pragma once
#include "Function.h"
#include <iostream>
#include <functional>


enum SOLUTION_OF_DIF_EQ {

	 EULER, EULER_CAUCHY, MODIFIED_EULER, RUNGE_KUTTA

};

static const double precision = 10e-6;
static const int number_of_steps = 10;
static const int MAX_STEP = 50000;
typedef Function<double> RealFunction;

struct solution {

	double value;
	double error;

};

solution solve_by_euler_method(RealFunction func, double x_0, \
	double y_0, double x, double eps = precision);


solution solve_by_euler_cauchy_method(RealFunction func, double x_0, \
	double y_0, double x, double eps = precision);


solution solve_by_modified_euler_method(RealFunction func, double x_0, \
	double y_0, double x, double eps = precision);


solution solve_by_runge_kutta_method(RealFunction func, double x_0, \
	double y_0, double x, double eps = precision);


void write_to_stream_values(RealFunction func, std::ostream& os, double x_0, \
	double y_0, double a, double b, double step, SOLUTION_OF_DIF_EQ sol = RUNGE_KUTTA, \
	double eps = precision);


std::vector<solution> solve_system_by_runge_kutta_method(std::vector<RealFunction> func, std::vector<double> x_0, \
	std::vector<double> y_0, std::vector<double> x, double eps = precision, std::function<void(std::vector<double>)> = nullptr);