#pragma once
#include "Function.h"
#include "grad.h"


static const double precision = 10e-6;
static const int MAX_STEP = 10000;
 
// функция возвращает значение истина, если корень функции f был найден на промежутку
// от left до right с точностью eps за количество шагов, меньше чем max_step, иначе
// возвращает значение ложь, а также значение корня на данном интервале
std::pair<bool, double> solve_nonlinear_equation(RationalFunction f, double left, \
	double right, double eps = precision, int max_step = MAX_STEP);