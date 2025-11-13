#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {

	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {

	(void)other;
	return *this;
}

float BitcoinExchange::strToFloat(const std::string &s) {
	
	std::istringstream iss(s);
	float value;
	iss >> value;
	return value;
}

int BitcoinExchange::checkValidFloat(const std::string &rate) {
	
	std::istringstream iss(rate);
	float value;
	iss >> value;
	if (iss.fail() || !iss.eof()) {
		return 1;
	}
	if (value < 0 || value > 1000) {
		return 1;
	}
	return 0;
}

bool isLeapYear(int year) {
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		return true;
	}
	return false;
}

int BitcoinExchange::checkValidDate(const std::string &date) {
	
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cout << "Date format invalid." << std::endl;
		return 1;
	}
	std::string year_str = date.substr(0, 4);
	std::string month_str = date.substr(5, 2);
	std::string day_str = date.substr(8, 2);

	int year = atoi(year_str.c_str());
	int month = atoi(month_str.c_str());
	int day = atoi(day_str.c_str());

	if (month < 1 || month > 12) {
		std::cout << "Error: Invalid month => " << month << std::endl;
		return 1;
	}
	if (day < 1 || day > 31) {
		std::cout << "Error: Invalid day => " << day << std::endl;
		return 1;
	}
	int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1]) {
		std::cout << "Error: Invalid day for the given month => " << day << std::endl;
		return 1;
	}
	return 0;
}

std::string BitcoinExchange::trim(const std::string &s) {
	
	size_t start = s.find_first_not_of(" \t");
	size_t end = s.find_last_not_of(" \t");

	if (start == std::string::npos) {
		return "";
	}
	return s.substr(start, end - start + 1);
}

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
	
	date = trim(date);
	value = trim(value);
	if (checkValidDate(date)) {
		std::cout << "Error: Invalid date => " << date << std::endl;
		return ;
	}
	if (checkValidFloat(value) ) {
		std::cout << "Error: Invalid value => " << value << std::endl;
		return ;
	}

	float value_float = strToFloat(value);

	std::map<std::string, float>::iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date) {
		std::cout << date << " => " << value_float << " = " << value_float * it->second << std::endl;
	} else {
		if (it == _database.begin()) {
			std::cout << "Error: No earlier date available for " << date << std::endl;
			return ;
		}
		--it;
		std::cout << date << " => " << value_float << " = " << value_float * it->second << std::endl;
	}
}

void BitcoinExchange::createDatabase() {
	
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open()) {
		std::cout << " Data file cannot be opened." << std::endl;
		return ;
	}
	
	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line)) {
		size_t delim = line.find(",");
		if (delim == std::string::npos) {
			std::cout << "Delimiter , hasn't been found." << std::endl;
			continue ;
		}
		std::string date = line.substr(0, delim);
		std::string rate_string = line.substr(delim + 1);
		float rate_float = atof(rate_string.c_str());
		_database[date] = rate_float;
	}
	dataFile.close();
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