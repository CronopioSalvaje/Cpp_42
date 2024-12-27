#pragma once

#include "colors.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include "utils.hpp"

class RPN{
    private:
        std::stack<int> stack;
        std::string m_exp;
        RPN(RPN const &cl);
        RPN &operator=(RPN const &cl);
    public:
        RPN(std::string const &exp);
        void checkExpression();
        void executeExpression();
        bool isValidChar(char c);
        bool areSeparatedVals(std::string const & str);
        bool areValidChars(std::string str);
        ~RPN();
};
