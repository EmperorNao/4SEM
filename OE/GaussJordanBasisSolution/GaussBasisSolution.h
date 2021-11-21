#pragma once
#include "Matrix.h"
#include <functional>

typedef Matrix<Fraction> Matr;

// ������� ���������� ����� ������ ������������� �� ������ �������� �
// ������� matr ������� � _i-��� ������ � _j-��� �������
int row_for_absmax_in_j_column_from_i_row(Matr matr, int _j, int _i);

// ������� ���������� �������� ������, ���� ������� ���������
// � ��������� ������ ��� ������ �������-������ ��� ������� matr
// ����� ���������� �������� ����
int forward_pass(Matr& matr);

// ������� ���������� �������� ������� ���������� ��� �������� indexes � ������� matr
std::vector<Fraction> basis_solution(Matr matr, std::vector<int> indexes);

// ������� ���������� ����������� ������� ����� ������� ������� ��� ������� ������� func � ������� ����������� matr
std::vector<Fraction> optimize_function_with_restrictions(std::function<Fraction(std::vector<Fraction>)> func, Matr matr);

// ������� ��������� ��������� �� ������������������� ������� ��������� �� n �� m � a 
int next_combination(std::vector<int>& a, int n, int m);