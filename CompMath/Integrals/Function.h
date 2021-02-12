#pragma once
#include "ArithmeticalExpression.h"


template <typename type>
class Function {

private:


	std::string formul;
	ArithmeticalExpression expression;
	size_t number_of_variables;


public:


	Function() {



	}


	Function(std::string _formul) {

		formul = _formul;
		expression.set_formula(_formul);
		number_of_variables = expression.get_variables().size();

	}


	void set_formul(std::string _formul) {

		formul = _formul;
		expression.set_formula(_formul);
		number_of_variables = expression.get_variables().size();

	}


	double operator() (double x) {

		return expression.count({ x });

	}


	double operator() (std::vector<double> x) {

		if (x.size() == number_of_variables) {

			return expression.count(x);

		}
		else {

			return 0;

		}

	}

	// Доделать класс








};


typedef Function<double> RationalFunction;