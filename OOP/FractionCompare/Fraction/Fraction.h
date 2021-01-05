#include <iostream>
using std::ostream;

class Fraction {

private:

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

	// метод сокращения дроби до несократимой
	void reduce();

	// оператор перегрузки вывода дроби obj в поток вывода os
	friend ostream& operator<<(ostream& os, const Fraction& obj);

	// операторы сравнения дробей left и right
	friend bool operator>(Fraction left, Fraction right);
	friend bool operator<(Fraction left, Fraction right);

};