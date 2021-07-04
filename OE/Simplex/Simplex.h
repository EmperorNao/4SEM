#pragma once
#include "Fraction.h"
#include "Matrix.h"


typedef Matrix<Fraction> Matr;


// функция возвращает вектор оптимального решения и значения функции при этом значении
// для функции с коэффициентами target и матрицей ограничений matr
std::pair<std::vector<Fraction>, std::vector<Fraction>> simplex(Matr& matr, std::vector<Fraction> target);



std::vector<Fraction> form_solution(Matr matr, \
	std::vector<int> all_variables, std::vector<int> basis_variables);


std::vector<Fraction> form_dual_solution(Matr matr, \
	std::vector<int> all_variables, std::vector<int> basis_variables);


int F(int i, std::vector<int> all_variables, std::vector<int> basis_variables);