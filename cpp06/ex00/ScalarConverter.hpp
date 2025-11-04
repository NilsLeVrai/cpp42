
#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <cmath>

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

class ScalarConverter {

	public:

		static void convert(const std::string &literal);
		
	private:
		
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
		ScalarConverter(const ScalarConverter &src);
};