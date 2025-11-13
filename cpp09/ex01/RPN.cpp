#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack), _input(other._input) {

    (void)other;
}

RPN& RPN::operator=(const RPN& other) {

    if (this != &other) {
        _stack = other._stack;
        _input = other._input;
    }
    return *this;
}

int RPN::calculate(const std::string& input) {
    /*
    Nls de demain
    */
    (void)input;
    std::cout << "coucou" << std::endl;
    return (0);
    //return 0;
}

const char* RPN::NonValidCharacterFound::what() const throw() {
	return "Non valid character found";
}

const char* RPN::FirstTwoNotDigits::what() const throw() {
	return "First two characters are not digits";
}

const char* RPN::NumberHasbeenFound::what() const throw() {
	return "Number has been found";
}

const char* RPN::InvalidNumberOfOperators::what() const throw() {
	return "Invalid number of operators";
}

/*
Checks:
    1) check les caracteres valides ("0123456789 \t*+-/")
    2) check si les 2 premiers sont des chiffres
    3) check si il n'y a que des chiffres et pas des nombres
    4) check si le nombre d'operateur = nombre de chiffres - 1
    5) je vois rien d'autre
*/