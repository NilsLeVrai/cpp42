#pragma once

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange {

    private:

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void run(const char *filename);
		void parseLine(std::string line);
		int checkFiles(const char *filename);
};