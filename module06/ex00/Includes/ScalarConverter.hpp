#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
    public:
        ~ScalarConverter();
       static void convert(std::string lit);
};

#endif
