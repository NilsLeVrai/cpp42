#pragma once

#include <iostream>
#include <stack>
#include <stdexcept>
#include <cstdlib>

class RPN {

    private:

        std::stack<int> _stackNumber;
        std::string     _input;

    public:

        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        int calculate(const std::string& input);
        int checkValidCharacters(const std::string& input);

        class NonValidCharacterFound : public std::exception {
        public:
            const char* what() const throw();
        };

        class FirstTwoNotDigits : public std::exception {
        public:
            const char* what() const throw();
        };

        class NumberHasbeenFound : public std::exception {
        public:
            const char* what() const throw();
        };

        class InvalidNumberOfOperators : public std::exception {
        public:
            const char* what() const throw();
        };

		class DivisionByZeroNotPossible : public std::exception {
        public:
            const char* what() const throw();
        };

};