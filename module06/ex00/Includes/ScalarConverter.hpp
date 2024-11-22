#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <sstream>
#include "colors.hpp"


class ScalarConverter
{
    private:
        ScalarConverter();
        static std::string getCharFromInt(int nb);
        static bool isAChar(std::string lit);
        static std::string getIntFromDouble(double d_converted);
        static std::string getFloatFromDouble(double d_converted);
        static bool hasDecimalPart(float d_converted);
        static void convertChar(std::string lit);

        static bool handleNan(std::string lit);
        static bool handleInf(std::string lit);
        static void print_err(int mask);
        static bool canConvertToDouble(std::string lit, double *result);
        static bool canConvertToInt(std::string lit, int *result);
        ~ScalarConverter();
    public:
        static void convert(std::string lit);
};

#endif
