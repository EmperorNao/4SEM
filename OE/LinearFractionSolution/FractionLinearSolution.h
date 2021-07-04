#pragma once
#include "Fraction.h"
#include "Matrix.h"
typedef Matrix<Fraction> Matr;


std::vector<Fraction> simplex_regularization(Matr matr, std::vector<Fraction> target, bool log);


std::vector<Fraction> form_solution(Matr matr, \
	std::vector<int> all_variables, std::vector<int> basis_variables);


std::vector<Fraction> simplex_artificial(Matr matr, std::vector<Fraction> target, bool log);


std::vector<Fraction> simplex(Matr _matr, std::vector<Fraction> target, bool log);

std::vector<Fraction> create_new_task(Matr& matr, \
	std::vector<Fraction> nom, std::vector<Fraction> denom);


Fraction get_target_value(std::vector<Fraction> nom, std::vector<Fraction> denom, std::vector<Fraction> sol);