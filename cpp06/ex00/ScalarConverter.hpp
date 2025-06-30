
#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>

class ScalarConverter {

	public:

		static void convert(const std::string &literal, int i, const std::string type);
		
	private:
		
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		ScalarConverter(const ScalarConverter &src);

		static bool stringToInt(const std::string& str, int& result);
};