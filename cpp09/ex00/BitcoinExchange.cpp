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



std::string BitcoinExchange::trim(const std::string &s) {

	size_t start = s.find_first_not_of(" \t");
	size_t end = s.find_last_not_of(" \t");

	if (start == std::string::npos) {
		return "";
	}
	s.substr(start, end - start + 1);
	return s;
}

int BitcoinExchange::checkValidDatas(const std::string &date, const std::string &rate) {

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return 1;
	std::istringstream ss(date);
	ss 
}

double BitcoinExchange::strToDouble(const std::string &s) {

	std::istringstream iss(s);
	double value;
	iss >> value;
	return value;
}

void BitcoinExchange::createDatabase() {

	std::ifstream dataFile("data.csv");

	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line)) {
		std::string date;
		std::string rate;

		std::istringstream ss(line);
		if ( !std::getline(ss, date, ',') || !std::getline(ss, rate))
			continue ;
		
		date = trim(date);
		rate = trim(rate);
		if (checkValidDatas(date, rate))
			_database[date] = strToDouble(rate);
	}
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
	createDatabase();
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