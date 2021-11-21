#pragma once
#include <iostream>


class Fraction {

private:

	// ��������� � �����������
	int nom;
	int denom;
	// ����� ���������� ��� ����� m � n
	int GCD(int m, int n);

public:

	// ������������
	// ����������� ��� ����� � ������������� ������ s
	Fraction(char* s);
	// ����������� ��� ����� � ������������� ���� ����� - ��������� n � ����������� d
	Fraction(int n = 0, int d = 1) : nom(n), denom(d) {};
	~Fraction() {



	}

	// ����� ���������� ����� �� ������������
	void reduce();

	// �������� ������������
	void operator=(int number);

	operator double() { return nom / denom; }
	// �������� ���������� ������ ����� obj � ����� ������ os
	friend std::ostream& operator<<(std::ostream& os, Fraction obj);

	friend std::istream& operator>>(std::istream& is, Fraction &obj);

	bool is_int() {

		reduce();
		return denom == 1;

	}

	Fraction float_part() {

		reduce();
		int sign = nom > 0 ? 1 : -1;
		return Fraction(abs(nom % denom), abs(denom));

	}

	// ��������� ��������� ������ left � right
	friend bool operator>(Fraction left, Fraction right);
	friend bool operator<(Fraction left, Fraction right);
	friend bool operator==(Fraction left, Fraction right);
	friend bool operator!=(Fraction left, Fraction right); 
	friend bool operator==(Fraction left, int right);
	friend bool operator!=(int left, Fraction right);
	friend bool operator==(int left, Fraction right);
	friend bool operator!=(Fraction left, int right);

	// �������� ���������
	friend Fraction operator*(Fraction a, Fraction b);
	friend Fraction operator+(Fraction a, Fraction b);
	friend Fraction operator-(Fraction a, Fraction b);
	friend Fraction operator/(Fraction a, Fraction b);

	friend Fraction operator*(Fraction a, int number);
	friend Fraction operator+(Fraction a, int number);
	friend Fraction operator-(Fraction a, int number);
	friend Fraction operator/(Fraction a, int number);

	friend Fraction operator*(int number, Fraction a);
	friend Fraction operator+(int number, Fraction a);
	friend Fraction operator-(int number, Fraction a);
	friend Fraction operator/(int number, Fraction a);

	friend void operator*=(Fraction& a, Fraction b);
	friend void operator+=(Fraction& a, Fraction b);
	friend void operator-=(Fraction& a, Fraction b);
	friend void operator/=(Fraction& a, Fraction b);

	friend void operator*=(Fraction& a, int number);
	friend void operator+=(Fraction& a, int number);
	friend void operator-=(Fraction& a, int number);
	friend void operator/=(Fraction& a, int number);


};


// ���������� ���������� �������� ����� obj
Fraction abs(Fraction obj);
Fraction log(Fraction obj);
Fraction pow(Fraction a, Fraction b);