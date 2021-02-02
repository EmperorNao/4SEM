#pragma once
#include "Fraction.h"
#include "Matrix.h"


typedef Matrix<Fraction> Matr;


// функция возвращает значения 
std::vector<Fraction> simplex(Matr matr, std::vector<int> target);