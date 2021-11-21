#pragma once
#include "Function.h"
#include "Gauss.h"
#include "grad.h"


const int MAX_ITERATION = 5000;
const double precision = 10e-6;


typedef Matrix<double> RealMatr;


std::pair<bool, std::vector<double>> solve_nonlinear_system(std::vector<RationalFunction> system, std::vector<double> solution,\
	double eps = precision, int max_iteration = MAX_ITERATION, std::function<void(std::vector<double>)> callback = nullptr);