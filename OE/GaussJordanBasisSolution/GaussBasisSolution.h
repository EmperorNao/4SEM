#pragma once
#include "Matrix.h"
#include <functional>

typedef Matrix<Fraction> Matr;

// функция возвращает номер строки максимального по модулю элемента в
// матрице matr начиная с _i-той строки в _j-том столбце
int row_for_absmax_in_j_column_from_i_row(Matr matr, int _j, int _i);

// функция возвращает значение истина, если система совместна
// и выполняет прямой ход метода Жордана-Гаусса для матрицы matr
// иначе возвращает значение ложь
int forward_pass(Matr& matr);

// Функция возвращает базисное решение переменных под номерами indexes в матрице matr
std::vector<Fraction> basis_solution(Matr matr, std::vector<int> indexes);

// Функция возвращает оптимальное решение среди опорных решений для целевой функции func и системы ограничений matr
std::vector<Fraction> optimize_function_with_restrictions(std::function<Fraction(std::vector<Fraction>)> func, Matr matr);

// Функция порождает следующее по лексикографическому порядку сочетание из n по m в a 
int next_combination(std::vector<int>& a, int n, int m);