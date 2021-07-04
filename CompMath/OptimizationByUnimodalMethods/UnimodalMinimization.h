#pragma once 
#include <iostream>
#include "Function.h"


enum UNIMODAL_MINIMIZATION_TYPE {

	OPTIMAL_SEARCH, HALF_DIVISION, FIBONACCI

};


static const double precision = 10e-6;
static const int FIBONACCI_N = 20;

// функция возвращает минимальную точку для функции func на отрезке унимодальности [left, right]
// с точностью eps методом оптимального поиска
double unimodal_optimal_search_minimization(RationalFunction func, double left, double right, double eps = precision);

// функция возвращает минимальную точку для функции func на отрезке унимодальности [left, right]
// с точностью eps методом половинного деления
double half_division_optimal_search_minimization(RationalFunction func, double left, double right, double eps = precision);

// функция возвращает минимальную точку для функции func на отрезке унимодальности [left, right]
// с точностью eps методом чисел фибоначчи
double fibonacci_optimal_search_minimization(RationalFunction func, double left, double right, double eps = precision);