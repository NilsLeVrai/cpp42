#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {} //add les vars plus tard

BitcoinExchange::~BitcoinExchange() {
} //delete?

/* BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    if (this != other) {
    }
}

BitcoinExchange& operator=(const BitcoinExchange& other) {

} */

void BitcoinExchange::parseLine(std::string line) {
	size_t delim = line.find("|");
	if (delim == std::string::npos) {
		std::cout << "Delimiter | hasn't been found." << std::endl;
		return ;
	}
	std::string date;
	std::string value;
	date = line.substr(0, delim);
	value = line.substr(delim + 1);

	date.erase(0, date.find_first_not_of(" \t"));
	date.erase(date.find_first_not_of(" \t") + 1);
	value.erase(0, value.find_first_not_of(" \t"));
	value.erase(value.find_first_not_of(" \t") + 1);

	std::cout << "Date: " << date << " | Value: " << value << std::endl;
}

int BitcoinExchange::checkFiles(const char *filename) {
	std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << " Input file cannot be opened." << std::endl;
        return 1;
    }
	std::ifstream dataFile("data.csv");
    if (!dataFile.is_open()) {
        std::cout << " Data file cannot be opened." << std::endl;
        return 1;
    }
	return 0;
}

void BitcoinExchange::run(const char *filename) {

	if (BitcoinExchange::checkFiles(filename)) {
		return ;
	}
	std::string line;
	std::ifstream inputFile(filename);
	std::getline(inputFile, line);
	if (line != "date | value") {
		std::cout << "First line not valid." << std::endl;
		return ;
	}
	while (std::getline(inputFile, line)) {
		BitcoinExchange::parseLine(line);
	}
}