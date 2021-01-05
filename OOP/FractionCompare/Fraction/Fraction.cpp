#include "Fraction.h"
#include <string>


ostream& operator<<(ostream& os, const Fraction& obj) {

	if ((obj.nom == 0) or (obj.denom == 1)) {

		os << obj.nom;
		return os;

	}
	os << obj.nom << "/" << obj.denom;
	return os;

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