#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "constucteur\n";
}

ScalarConverter::~ScalarConverter() {
	std::cout << "destucteur\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	std::cout << "copieur\n";
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {

	if (this == &src)
		return (*this);
	//truc
	return (*this);
}

void ScalarConverter::convert(const std::string &src, int i, const std::string type) {
	int		n;
	double	d;
	float	f;

	if (type == "char") {
		char c;
		int tmp = i;

		if (src == "nanf" || src == "+inff" || src == "-inff") {
			convert(src, i, "float");
			return;
		}
		i++;
		while (std::isspace(src[i]))
			i++;
		if (src[i] != '\0') {
			std::cout << "Not a valid char" << std::endl;
			return ;
		}
		c = src[tmp];
		std::cout << BLUE BOLD "char detected" RESET << std::endl;
		if (std::isprint(c))
			std::cout << "char   : '" << c << "'" << std::endl;
		else
			std::cout << " Non displayable" << std::endl;

		n = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);

		std::cout << "int    :"    << " " << n << std::endl;
		std::cout << std::fixed << std::showpoint << std::setprecision(1);
		std::cout << "float  :"  << " " << f << "f" << std::endl;
		std::cout << "double :" << " " << d << std::endl;
	}
	else if (type == "double") {
		std::cout << BLUE BOLD "double detected" RESET << std::endl;
	}

	else if (type == "float") {
		std::cout << BLUE BOLD "float detected" RESET << std::endl;
	}

	else if (type == "int") {
		if (src == "nan" || src == "+inf" || src == "-inf") {
			convert(src, i, "double");
			return;
		}
		
		std::istringstream iss(src);
		iss >> n;
		
		if (iss.fail()) {
			std::cout << RED BOLD "Conversion error: Not a valid integer" RESET << std::endl;
			return;
		}
		
		std::string remaining;
		std::getline(iss, remaining);
		for (size_t j = 0; j < remaining.length(); ++j) {
			if (std::isspace(remaining[j]) || remaining[j] == '\0') {
				continue;
			}
			std::cout << RED BOLD "Conversion error: Extra characters after integer" RESET << std::endl;
			return;
		}
		std::cout << BLUE BOLD "int detected" RESET << std::endl;
		
		f = static_cast<float>(n);
		d = static_cast<double>(n);
		
		std::cout << "char   : impossible" << std::endl;
		std::cout << "int    : " << n << std::endl;
		std::cout << std::fixed << std::showpoint << std::setprecision(1);
		std::cout << "float  : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
	}
}
