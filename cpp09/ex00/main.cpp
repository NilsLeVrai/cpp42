#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Usage: ./btc file.csv" <<std::endl;
        return 1;
    }
    BitcoinExchange bitcoinObj;
    bitcoinObj.run(argv[1]);

    return 0;
}