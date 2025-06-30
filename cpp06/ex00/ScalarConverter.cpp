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
		int len = 0;

		if (src == "nanf" || src == "+inff" || src == "-inff") {
			convert(src, i, "float");
			return;
		}

		while (src[i + len])
			len++;
		if (len > 1) {
			std::cout << "char   :"   << " impossible" << std::endl;
			std::cout << "int    :"    << " impossible" << std::endl;
			std::cout << "float  :"  << " impossible" << std::endl;
			std::cout << "double :" << " impossible" << std::endl;
			return;
		}

		c = src[i];

		std::cout << "char   :";
		if (std::isprint(c))
			std::cout << " '" << c << "'" << std::endl;
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
		std::cout << "double\n" << std::endl;
	}

	else if (type == "float") {
		std::cout << "float\n" << std::endl;
	}

	else if (type == "int") {
		if (src == "nan" || src == "+inf" || src == "-inf") {
			convert(src, i, "double");
			return;
		}

		std::istringstream iss(src);
		iss >> n;

		if (iss.fail()) {
			std::cout << "char   : impossible" << std::endl;
			std::cout << "int    : impossible" << std::endl;
			std::cout << "float  : impossible" << std::endl;
			std::cout << "double : impossible" << std::endl;
			return;
		}

		std::string remaining;
		std::getline(iss, remaining);
		for (size_t j = 0; j < remaining.length(); ++j) {
			if (remaining[j] != ' ' && remaining[j] != '\t') {
				std::cout << "char   : impossible" << std::endl;
				std::cout << "int    : impossible" << std::endl;
				std::cout << "float  : impossible" << std::endl;
				std::cout << "double : impossible" << std::endl;
				return;
			}
		}

		f = static_cast<float>(n);
		d = static_cast<double>(n);

		std::cout << "char   : impossible" << std::endl;
		std::cout << "int    : " << n << std::endl;
		std::cout << std::fixed << std::showpoint << std::setprecision(1);
		std::cout << "float  : " << f << "f" << std::endl;
		std::cout << "double : " << d << std::endl;
	}
}
