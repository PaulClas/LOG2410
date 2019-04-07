#include <iostream>
#include <exception>

#include "Test_TP5.h"

int main() {
	try {
		Test_TP5 TestCorrection;

		TestCorrection.executeProxyTest();
		TestCorrection.executeCompositeTest();
		TestCorrection.executeVisitorTest();
		TestCorrection.executeCommandTest();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception lancée" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}