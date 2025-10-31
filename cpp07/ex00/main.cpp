#include "whatever.hpp"
#include <iostream>

int main( void ) 
{

	//Integers
	int x = 54;
	int y = 21;

	std::cout << BOLD_MAGENTA"--- INTEGERS ---\n" << RESET << std::endl;
	std::cout << BOLD_GREEN << "x = " << BOLD_GREEN << x << RESET << BOLD_YELLOW << ", y = " << y << RESET << std::endl;
	::swap(x, y);
	std::cout << BOLD_GREEN << "x = " << BOLD_GREEN << x << RESET << BOLD_YELLOW << ", y = " << y << RESET << std::endl;
	std::cout << BOLD_CYAN "min(x, y) = " << ::min(x, y) << RESET << std::endl;
	std::cout << BOLD_RED "max(x, y) = " << ::max(x, y) << RESET << std::endl;


	//Strings
	std::string a = "423";
	std::string b = "5";

	std::cout << BOLD_MAGENTA"\n--- STRINGS ---\n" << RESET << std::endl;
	std::cout << BOLD_GREEN << "a = " << BOLD_GREEN << a << RESET << BOLD_YELLOW << ", b = " << b << RESET << std::endl;
	::swap(a, b);
	std::cout << BOLD_GREEN << "a = " << BOLD_GREEN << a << RESET << BOLD_YELLOW << ", b = " << b << RESET << std::endl;
	std::cout << BOLD_CYAN << "min(a, b) = " << ::min(a, b) << RESET << std::endl;
	std::cout << BOLD_RED << "max(a, b) = " << ::max(a, b) << RESET << std::endl;


	//Chars
	char c = '+';
	char d = '-';

	std::cout << BOLD_MAGENTA"\n--- CHARACTERS ---\n" << RESET << std::endl;
	std::cout << BOLD_GREEN << "c = " << BOLD_GREEN << c << RESET << BOLD_YELLOW << ", d = " << d << RESET << std::endl;
	::swap(c, d);
	std::cout << BOLD_GREEN << "c = " << BOLD_GREEN << c << RESET << BOLD_YELLOW << ", d = " << d << RESET << std::endl;
	std::cout << BOLD_CYAN << "min(c, d) = " << ::min(c, d) << RESET << std::endl;
	std::cout << BOLD_RED << "max(c, d) = " << ::max(c, d) << RESET << std::endl;


	//Doubles
	double pi = 3.14159;
	double e = 2.71828;

	std::cout << BOLD_MAGENTA"\n--- DOUBLES ---\n" << RESET << std::endl;
	std::cout << BOLD_GREEN << "pi = " << BOLD_GREEN << pi << RESET << BOLD_YELLOW << ", e = " << e << RESET << std::endl;
	::swap(pi, e);
	std::cout << BOLD_GREEN << "pi = " << BOLD_GREEN << pi << RESET << BOLD_YELLOW << ", e = " << e << RESET << std::endl;
	std::cout << BOLD_CYAN << "min(pi, e) = " << ::min(pi, e) << RESET << std::endl;
	std::cout << BOLD_RED << "max(pi, e) = " << ::max(pi, e) << RESET << std::endl;

	return 0;
}