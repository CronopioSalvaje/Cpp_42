#include "../Includes/ScalarConverter.hpp"
#include "../Includes/utils.hpp"
#include <iomanip>  // Pour std::setprecision
#include <cmath>

ScalarConverter::ScalarConverter()
{    
}

void ScalarConverter::convert(std::string lit)
{
    int i;
    float f;
    
    i = std::atoi(lit.c_str());
    f = std::atof(lit.c_str());
    std::cout << "char: " << getCharFromInt(static_cast<int>(f)) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
    std::cout << "double: "<< f << std::endl;
}

ScalarConverter::~ScalarConverter()
{
   
}
