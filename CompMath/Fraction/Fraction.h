#pragma once
#include <iostream>


class Fraction {

private:

	// числитель и знаменатель
	int nom;
	int denom;
	// метод возвращает НОД чисел m и n
	int GCD(int m, int n);

public:

	// конструкторы
	// конструктор для дроби в представлении строки s
	Fraction(char* s);
	// конструктор для дроби в представлении двух чисел - числителя n и знаменателя d
	Fraction(int n = 0, int d = 1) : nom(n), denom(d) {};
	~Fraction() {



	}

	// метод сокращения дроби до несократимой
	void reduce();

	// оператор присваивания
	void operator=(int number);

	operator double() { return nom / denom; }
	// оператор перегрузки вывода дроби obj в поток вывода os
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

	// операторы сравнения дробей left и right
	friend bool operator>(Fraction left, Fraction right);
	friend bool operator<(Fraction left, Fraction right);
	friend bool operator==(Fraction left, Fraction right);
	friend bool operator!=(Fraction left, Fraction right); 
	friend bool operator==(Fraction left, int right);
	friend bool operator!=(int left, Fraction right);
	friend bool operator==(int left, Fraction right);
	friend bool operator!=(Fraction left, int right);

	// бинарные операторы
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


// возвращает абсолютное значение дроби obj
Fraction abs(Fraction obj);
Fraction log(Fraction obj);
Fraction pow(Fraction a, Fraction b);