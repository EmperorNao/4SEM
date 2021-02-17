#pragma once 
#include <iostream>
#include "Function.h"


enum UNIMODAL_MINIMIZATION_TYPE {

	OPTIMAL_SEARCH, HALF_DIVISION, FIBONACCI

};


static const double precision = 10e-6;
static const int FIBONACCI_N = 20;


double unimodal_optimal_search_minimization(RationalFunction func, double left, double right, double eps = precision);


double half_division_optimal_search_minimization(RationalFunction func, double left, double right, double eps = precision);


double fibonacci_optimal_search_minimization(RationalFunction func, double left, double right, double eps = precision);