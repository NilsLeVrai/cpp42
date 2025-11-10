#pragma once

#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange {

    private:

        const char *_file;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void run(const char *filename);
};