#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>

class ScalarConverter
{
    private:
        ScalarConverter();
        static std::string getCharFromInt(int nb);
        static int checkType(std::string lit);
        static void printLimits();
        static void checklimits(std::string lit);
        static bool isAChar(std::string lit);
        static void debugState(bool state);
        static void convertChar(std::string lit);
        static void convertInt(std::string lit);
        static bool canConvertToDouble(std::string lit, double *result);
        static bool canConvertToInt(std::string lit, int *result);
        ~ScalarConverter();
    public:
        static void convert(std::string lit);
};

#endif
