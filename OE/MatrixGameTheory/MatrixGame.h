#pragma once
#include "SequentialUpgradingEstimates.h"


std::pair<std::vector<Fraction>, std::vector<Fraction>>  dual_simplex(Matr _matr, std::vector<Fraction> target, bool log = false);