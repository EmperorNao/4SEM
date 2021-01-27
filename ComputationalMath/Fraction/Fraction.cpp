#include "Fraction.h"
#include <string>


std::istream& operator>>(std::istream& is, Fraction& obj) {

 	is >> obj.nom;
	return is;

}


std::ostream& operator<<(std::ostream& os, Fraction obj) {

	if (obj.denom < 0) {

		obj.nom *= -1;
		obj.denom *= -1;

	}
	if ((obj.nom == 0) or (obj.denom == 1)) {

		os << obj.nom;
		return os;

	}
	os << obj.nom << "/" << obj.denom;
	return os;

}


Fraction operator*(Fraction a, Fraction b) {

	Fraction new_fraction(a.nom * b.nom, a.denom * b.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator+(Fraction a, Fraction b) {

	Fraction new_fraction(a.nom * b.denom + b.nom * a.denom, a.denom * b.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator-(Fraction a, Fraction b) {

	Fraction new_fraction(a.nom * b.denom - b.nom * a.denom, a.denom * b.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator/(Fraction a, Fraction b) {

	if (b.nom != 0) {

		Fraction new_fraction(a.nom * b.denom, a.denom * b.nom);
		new_fraction.reduce();
		return new_fraction;

	}

	Fraction new_fraction;
	return new_fraction;

}


Fraction operator*(Fraction a, int number) {

	Fraction new_fraction(a.nom * number, a.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator+(Fraction a, int number) {

	Fraction new_fraction(a.nom + number * a.denom, a.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator-(Fraction a, int number) {

	Fraction new_fraction(a.nom - number * a.denom, a.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator/(Fraction a, int number) {

	if (number != 0) {

		Fraction new_fraction(a.nom, a.denom * number);
		new_fraction.reduce();
		return new_fraction;

	}

	Fraction new_fraction;
	return new_fraction;

}


Fraction operator*(int number, Fraction a) {

	return a * number;

}


Fraction operator+(int number, Fraction a) {

	return a + number;

}


Fraction operator-(int number, Fraction a) {

	Fraction new_fraction( number * a.denom - a.nom, a.denom);
	new_fraction.reduce();
	return new_fraction;

}


Fraction operator/(int number, Fraction a) {

	if (a.nom != 0) {

		Fraction new_fraction(number * a.denom, a.nom);
		new_fraction.reduce();
		return new_fraction;

	}

	Fraction new_fraction;
	return new_fraction;

}


bool operator>(Fraction left, Fraction right) {

	long long left_nom = left.nom * right.denom;
	long long right_nom = right.nom * left.denom;
	return left_nom > right_nom;

}


bool operator<(Fraction left, Fraction right) {

	long long left_nom = left.nom * right.denom;
	long long right_nom = right.nom * left.denom;
	return left_nom < right_nom;

}


void operator*=(Fraction a, Fraction b) {



}


void operator*=(Fraction& a, Fraction b) {

	a = a * b;

}


void operator+=(Fraction& a, Fraction b) {

	a = a + b;

}


void operator-=(Fraction& a, Fraction b) {

	a = a - b;

}


void operator/=(Fraction& a, Fraction b) {

	a = a / b;

}


void operator*=(Fraction& a, int number) {

	a = a * number;

}


void operator+=(Fraction& a, int number) {

	a = a + number;

}


void operator-=(Fraction& a, int number) {

	a = a - number;

}


void operator/=(Fraction& a, int number) {

	a = a / number;

}


int Fraction::GCD(int m, int n) {

	if (m < n) {

		int t = m;
		m = n;
		n = t;

	}

	int r = 1;
	while (n != 0) {

		r = m % n;
		m = n;
		n = r;

	}
	return m;

}


Fraction::Fraction(char* s) {

	char* t = strchr(s, '/');

	denom = 1;
	if (t != NULL) {

		*t = '\0';
		t++;
		denom = std::stoi(t); 

	}

	nom = std::stoi(s);

}


void Fraction::reduce() {

	int gcd = GCD(abs(nom), denom );
	nom /= gcd;
	denom /= gcd;

}


void Fraction::operator=(int number) {

	nom = number;

}


Fraction abs(Fraction obj) {

	if (obj < Fraction(0)) {

		obj = -1 * obj;

	}

	return obj;

}