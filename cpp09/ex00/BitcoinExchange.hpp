#pragma once

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange {

    private:

		std::map<std::string, double> _database;
		void parseLine(std::string line);
		std::string trim(const std::string &s);
		double	strToDouble(const std::string &rate);
		int		checkValidDatas(const std::string &date, const std::string &rate);
		
		public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
		
        void run(const char *filename);
		int checkFiles(const char *filename);
		void createDatabase();
};