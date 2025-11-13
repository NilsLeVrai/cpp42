#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"<expression_RPN>\"" << std::endl;
        return 1;
    }
    RPN rpnCalculator;
	std::string input = argv[1];
    try {
        int result = rpnCalculator.calculate(input);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
