#pragma once
#include "Function.h"
#include "Matrix.h"

static const double precision = 1e-5;


static Matrix<double> A(4, 4);
static Matrix<double> t(4, 4);


// ������� ���������� �������� ��������� ������� func �� � �� b
// ����������� � ������� ������ ���������������� � ����������� ����� n � ��������� eps
double integrate_by_central_rectangles(RationalFunction func, double a, double b, int n = 8, double eps = precision);

// ������� ���������� �������� ��������� ������� func �� � �� b
// ����������� � ������� ������ �������� � ����������� ����� n � ��������� eps
double integrate_by_trapezoids(RationalFunction func, double a, double b, int n = 8, double eps = precision);

// ������� ���������� �������� ��������� ������� func �� � �� b
// ����������� � ������� ������ �������� � ����������� ����� n � ��������� eps
double integrate_by_parabols(RationalFunction func, double a, double b, int n = 8, double eps = precision);

// ������� ���������� �������� ��������� ������� func �� � �� b
// ����������� � ������� ������ ������ � ����������� ����� n
double integrate_by_gauss(RationalFunction func, double a, double b, int n = 4);



