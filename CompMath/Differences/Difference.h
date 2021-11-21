#include <iostream>
#include "Matrix.h"

// ������� ���������� �������� ����� ���������� �� ���������� values � ������ points
// ������������� �� �������� ���������, ���� fin ������, ����� �� ����������� ���������
double calculate_poly_with_n_knots_in_x(std::vector<double> points, std::vector<double> values, double x, bool fin);

// ������� ������� k-��� �������� ������ n ��� ������� matr ������� � ������ points
// ���� fin ������, �� ������� �������� ��������, ����� �����������
void calculate_k_fin_diff_at_n_upside(Matrix<double>& matr, std::vector<double> points, int k, int n, bool fin);

// ������� ������� ������� ��������� matr �������� �� ���������� � ������ points
// ���� fin ������, �� ������� �������� ��������, ����� �����������
void count_table(Matrix<double>& matr, std::vector<double> points, bool fin);