#include "grad.h"


struct crushing_config : config {

	double beta = 0.9;
	double gamma = 0.9;

};


std::pair<bool, std::vector<double>> crushing_gradient_descent(RealFunction& func, \
	crushing_config config);