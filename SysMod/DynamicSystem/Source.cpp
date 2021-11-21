#include "DynamicSystem.h"
#include <locale.h>


int main() {

	setlocale(LC_ALL, "RUS");
	DynamicSystem sys({ 0, 0, 0, 0 }, {0, 0.05, 0, 3.0915});

	sys.simulate(6, 0.1 , 0);

}