#include "iter.hpp"

int main()
{

	//Int array test

	std::cout << BOLD_MAGENTA << "--- INTEGERS ---\n" << RESET << std::endl;
	int intArray[5] = {16, 2, 98, 29, 12};
	std::cout << BOLD_GREEN << "Non-const array elements: " << RESET;
	::iter(intArray, 5, print);

	std::cout << RESET << std::endl;

	const int constIntArray[5] = {19, 11, 1, 6, 5};
	std::cout << BOLD_YELLOW << "Const array elements: " << RESET;
	::iter(constIntArray, 5, print);

	std::cout << RESET << std::endl << std::endl;

	//std::string array test
	std::cout << BOLD_MAGENTA << "--- STRINGS ---\n" << RESET << std::endl;
	std::string strArray[5] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron"};
	std::cout << BOLD_GREEN << "Non-const array elements: " << RESET;
	::iter(strArray, 5, print);

	std::cout << RESET << std::endl;

	const std::string constStrArray[5] = {"Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon"};
	std::cout << BOLD_YELLOW << "Const array elements: " << RESET;
	::iter(constStrArray, 5, print);

	std::cout << RESET << std::endl << std::endl;

	//double array test
	std::cout << BOLD_MAGENTA << "--- DOUBLES ---\n" << RESET << std::endl;
	double doubleArray[5] = {3.14159, 1.61803, 2.71828, 1.41421, 0.99999};
	std::cout << BOLD_GREEN << "Non-const array elements: " << RESET;
	::iter(doubleArray, 5, print);

	std::cout << RESET << std::endl;

	const double constDoubleArray[5] = {3.14159, 1.61803, 2.71828, 1.41421, 0.99999};
	std::cout << BOLD_YELLOW << "Const array elements: " << RESET;
	::iter(constDoubleArray, 5, print);

	std::cout << RESET << std::endl;

	return 0;
}