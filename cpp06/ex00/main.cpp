
#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "./Scalar [argv[1]]\n"; 
		return 1;
	}
	int i = 0;
	int sign = 1;
	
	std::string value = argv[1];

	while (std::isspace(value[i]))
		i++;
	while (value[i] == '+' || value[i] == '-')
	{
		if (value[i] == '-')
			sign *= -1;
		i++;
	}
	if (!std::isdigit(value[i]))
	{
		ScalarConverter::convert(value, i, "char");
		return 0;
	}
	while (std::isdigit(value[i]))
		i++;
	if (value[i] == '.')
	{
		i++;
		while (std::isdigit(value[i]))
			i++;
		if (value[i] == 'f')
			ScalarConverter::convert(value, i, "float");
		else
			ScalarConverter::convert(value, i, "double");
	}
	else
		ScalarConverter::convert(value, i, "int");
}
