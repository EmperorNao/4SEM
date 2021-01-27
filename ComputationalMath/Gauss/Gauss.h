#pragma once
#include "Matrix.h"
#include "Fraction.h"


typedef std::vector<Fraction> Arr;
typedef Matrix<Fraction> Matr;

// возвращает номер строки с максимальным элементом в матрице matr
// начиная с i-той строки j-того столбца
int row_for_absmax_in_j_column_from_i_row(Matr matr, int _j, int _i);

// прямой ход метода Гаусса в матрице matr, функция возвращает
// количество обменов строк
int forward_pass(Matr& matr);

// обратный ход метода Гаусса
// функция возвращает массив решений матрицы matr, 
// где за столбец расширенной матрицы берётся последний столбец, если 
// last = -1, иначе берётся last
Arr back_propagation(Matr& matr, int last = -1);

// функция возвращает значение определителя матрицы matr
Fraction determinant(Matr matr);

// функция возвращает обратную матрицу к matr
Matr inverse(Matr matr);