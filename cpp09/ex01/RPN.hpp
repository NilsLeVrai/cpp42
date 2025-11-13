#pragma once

#include <iostream>

class RPN {

    private:


    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        int calculate(const std::string& expression);
};