#pragma once
#include "Matrix.h"
#include "Iteration.h"


// ������� ���������� ������������� ������ v
std::vector<double> normalyze_vector(std::vector<double> v);

// ������� ���������� ������������ �� ������ ����������� �������� � 
// ��������������� ��� ����������� ������ ��� ������� matr � �������� eps
std::pair<double, std::vector<double>> max_eigenvalue_eigenvector(Matr& matr,\
	double eps = precision);


double operator*(std::vector<double> a, std::vector<double> b);

std::vector<double> operator/(std::vector<double> a, double b);
std::vector<double> operator-(std::vector<double> a, std::vector<double> b);

