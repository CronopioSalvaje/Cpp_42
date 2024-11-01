#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        static std::string getCharFromInt(int nb);
        static int checkType(std::string lit);
        static void ScalarConverter::printLimits();
        static void ScalarConverter::checklimits(std::string lit);
        static void displayResults(std::string ch,std::string in,std::string fl,std::string db);
        ~ScalarConverter();
    public:
        static void convert(std::string lit);
};

#endif
