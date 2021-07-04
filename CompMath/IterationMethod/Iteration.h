#pragma once
#include "Matrix.h"


typedef Matrix<double> Matr;
const double precision = 10e-6;

// функци€ возвращает решение системы линейных уравнений matr c точностью eps
std::vector<double> solve_linear_system(Matr& matr, double eps = precision);

// функци€ возвращает значение norm норму матрицы matr, если norm > 0, 
// иначе, если norm = -1, возвращает значение бесконечной нормы matr
double matr_norm(Matr& matr, int norm);

// функци€ возвращает значение norm нормы массива arr, если norm > 0, 
// иначе, если norm = -1, возвращает значение бесконечной нормы matr
double vector_norm(std::vector<double> arr, int norm);