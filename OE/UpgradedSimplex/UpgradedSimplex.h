#pragma once
#include "Simplex.h"


std::vector<Fraction> simplex_artificial_basis(Matr matr, std::vector<int> target);

std::vector<Fraction> simplex_regularization(Matr matr, std::vector<Fraction> target, bool log);