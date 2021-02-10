#pragma once
#include "Fraction.h"
#include "Matrix.h"


typedef Matrix<Fraction> Matr;


// функция возвращает вектор оптимального решения и значения функции при этом значении
// для функции с коэффициентами target и матрицей ограничений matr
std::vector<Fraction> simplex(Matr matr, std::vector<int> target);


// функция возвращает решение по симплекс-таблице matr по переменным системы all_variables 
// и базисным переменным basis_variables
std::vector<Fraction> form_solution(Matr matr, std::vector<int> all_variables, std::vector<int> basis_variables);