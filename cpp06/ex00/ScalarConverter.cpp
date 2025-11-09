#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	// Constructor
}
ScalarConverter::~ScalarConverter() {
	// Destructor
}
ScalarConverter::ScalarConverter(const ScalarConverter &) {
	// Copy constructor
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
	// Copy assignment operator
	return *this;
}

void ScalarConverter::convert(const std::string &literal)
{

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		char c = literal[0];
		double d = static_cast<double>(c);
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c) << "\n";
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f\n";
		std::cout << "double: " << d << "\n";
		return;
	}

	if (literal == "nan" || literal == "+inf" || literal == "-inf"
		|| literal == "nanf" || literal == "+inff" || literal == "-inff") {

		std::string base = literal;

		if (literal.size() > 1 && literal[literal.size() - 1] == 'f') {
			base = literal.substr(0, literal.size() - 1);
		}

		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	if (literal == "+inff" || literal == "+inf") {
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	} else if (literal == "-inff" || literal == "-inf") {
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	} else {
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}

		return;
	}

	char *end;
	double d = std::strtod(literal.c_str(), &end);

	if (*end == 'f' && *(end + 1) == '\0') {

	} else if (*end != '\0') {
		std::cout << "Error: invalid literal\n";
		return;
	}

	if (std::isnan(d) || d < 0 || d > 127 || !std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";

	if (std::isnan(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << "\n";
}
