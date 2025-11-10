#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Usage: ./btc file.csv" <<std::endl;
        return 1;
    }
    BitcoinExchange bitcoinObj;
    bitcoinObj.run(argv[1]);

    return 0;
}