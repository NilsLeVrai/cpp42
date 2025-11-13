#pragma once

#include <iostream>
#include <stack>
#include <stdexcept>
#include <cstdlib>

class RPN {

    private:

        std::stack<int> _stack;
        std::string     _input;

    public:

        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        int calculate(const std::string& input);

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

};