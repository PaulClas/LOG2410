#include <iostream>
#include <exception>

#include "Test_TP4.h"

int main() {
	try {
		Test_TP4 TestCorrection;

		TestCorrection.executeProxyTest();
		TestCorrection.executeCompositeTest();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception lancée" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}