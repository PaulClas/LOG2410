#include <iostream>
#include <exception>

#include "Test_TP4.h"

using namespace std;

int main() {
	try {
		Test_TP4 TestCorrection;

		TestCorrection.executeProxyTest();
		TestCorrection.executeCompositeTest();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception lanc�e" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}