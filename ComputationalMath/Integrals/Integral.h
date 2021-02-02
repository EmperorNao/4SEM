#pragma once
#include "Function.h"
#include "Matrix.h"

static const double precision = 1e-5;


static Matrix<double> A(4, 4);
static Matrix<double> t(4, 4);


// функция возвращает значение интеграла функции func от а до b
// вычисленное с помощью метода прямоугольникова с количеством шагов n и точностью eps
double integrate_by_central_rectangles(RationalFunction func, double a, double b, int n = 8, double eps = precision);

// функция возвращает значение интеграла функции func от а до b
// вычисленное с помощью метода трапеций с количеством шагов n и точностью eps
double integrate_by_trapezoids(RationalFunction func, double a, double b, int n = 8, double eps = precision);

// функция возвращает значение интеграла функции func от а до b
// вычисленное с помощью метода симпсона с количеством шагов n и точностью eps
double integrate_by_parabols(RationalFunction func, double a, double b, int n = 8, double eps = precision);

// функция возвращает значение интеграла функции func от а до b
// вычисленное с помощью метода Гаусса с количеством шагов n
double integrate_by_gauss(RationalFunction func, double a, double b, int n = 4);



