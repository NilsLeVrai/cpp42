#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {

	private:

		int								checkValidDate(const std::string &date);
		int								checkValidFloat(const std::string &rate);
		void							parseLine(std::string line);
		float							strToFloat(const std::string &rate);
		std::string						trim(const std::string &s);
		std::map<std::string, float>	_database;
		
	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		
		int								checkFiles(const char *filename);
		void							createDatabase();
		void							run(const char *filename);
};