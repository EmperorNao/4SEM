#include "grad.h"


struct crushing_config : config {

	double beta = 0.9;
	double gamma = 0.9;

};


// функция возвращает значение истина, если минимальное значение func было найдено
// за количество шагов, меньшее чем ограничение, а также возвращает параметры минимальной точки
std::pair<bool, std::vector<double>> crushing_gradient_descent(RealFunction& func, \
	crushing_config config);