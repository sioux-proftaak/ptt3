#include <iostream>

#include "Calculator.h"

int main() {
	Calculator calculator;
	int result = calculator.add(2, 3);
	std::cout << "2 + 3 = " << result << std::endl;
}

