#include "../Includes/ScalarConverter.hpp"
#include "../Includes/utils.hpp"
#include <iomanip>  // Pour std::setprecision
#include <cmath>

ScalarConverter::ScalarConverter()
{    
}

void ScalarConverter::convert(std::string lit)
{
    float f;
    int type;

    f = std::atof(lit.c_str());
    type = checkType(lit);
    if (type == "nan")
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "nan" << "f" << std::endl;
        std::cout << "double: "<< "nan" << std::endl;
    }
    else 
    {
        std::cout << "char: " << getCharFromInt(static_cast<int>(f)) << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        std::cout << "double: "<< f << std::endl;
    }
}

ScalarConverter::~ScalarConverter()
{
   
}
