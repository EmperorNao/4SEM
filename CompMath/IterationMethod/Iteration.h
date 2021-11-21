#pragma once
#include "Matrix.h"


typedef Matrix<double> Matr;
const double precision = 10e-6;

// ������� ���������� ������� ������� �������� ��������� matr c ��������� eps
std::vector<double> solve_linear_system(Matr& matr, double eps = precision);

// ������� ���������� �������� norm ����� ������� matr, ���� norm > 0, 
// �����, ���� norm = -1, ���������� �������� ����������� ����� matr
double matr_norm(Matr& matr, int norm);

// ������� ���������� �������� norm ����� ������� arr, ���� norm > 0, 
// �����, ���� norm = -1, ���������� �������� ����������� ����� matr
double vector_norm(std::vector<double> arr, int norm);