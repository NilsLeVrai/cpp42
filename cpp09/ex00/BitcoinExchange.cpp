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

void BitcoinExchange::run(const char *filename) {
    std::ifstream _file(filename);
    if (!_file.is_open()) {
        std::cout << " File cannot be opened" << std::endl;
        return;
    }

}