#include <iostream>
#include "Matrix.h"

// функция возвращает значение точки многочлена со значениями values в точках points
// апроксимирует по конечным разностям, если fin истина, иначе по разделенным разностям
double calculate_poly_with_n_knots_in_x(std::vector<double> points, std::vector<double> values, double x, bool fin);

// функция считает k-тую разность строки n для матрицы matr функции в точках points
// если fin истина, то считает конечную разность, иначе разделенную
void calculate_k_fin_diff_at_n_upside(Matrix<double>& matr, std::vector<double> points, int k, int n, bool fin);

// функция считает таблицу разностей matr полинома со значениями в точках points
// если fin истина, то считает конечные разности, иначе разделенные
void count_table(Matrix<double>& matr, std::vector<double> points, bool fin);