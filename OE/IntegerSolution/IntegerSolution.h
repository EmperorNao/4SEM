#pragma once
#include "SequentialUpgradingEstimates.h"


std::vector<Fraction> gomori_algorithm(Matr matr, std::vector<Fraction> target, bool log = false);

Matr simplex_(Matr matr, std::vector<int>& basis_variables, std::vector<int>& all_variables, bool log = false);
Matr upgrading_estimation_(Matr& matr, std::vector<int>& basis_variables, std::vector<int>& all_variables, bool log = false);
bool is_positive_condition_row(Matr matr);
Matr simplex_artificial(Matr matr, std::vector<Fraction> target, std::vector<int>& basis_variables, std::vector<int>& all_variables, bool log = false);
bool is_positive_condition_column(Matr matr);
bool is_integer_condition(Matr matr);
std::vector<Fraction> form_solution(Matr matr, \
	std::vector<int> all_variables, std::vector<int> basis_variables);

