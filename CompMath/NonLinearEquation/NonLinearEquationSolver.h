#pragma once
#include "Function.h"
#include "grad.h"


static const double precision = 10e-6;
static const int MAX_STEP = 10000;
 
// ������� ���������� �������� ������, ���� ������ ������� f ��� ������ �� ����������
// �� left �� right � ��������� eps �� ���������� �����, ������ ��� max_step, �����
// ���������� �������� ����, � ����� �������� ����� �� ������ ���������
std::pair<bool, double> solve_nonlinear_equation(RationalFunction f, double left, \
	double right, double eps = precision, int max_step = MAX_STEP);