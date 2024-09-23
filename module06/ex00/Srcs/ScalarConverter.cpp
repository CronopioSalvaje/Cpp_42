#include "../Includes/ScalarConverter.hpp"
#include "../Includes/utils.hpp"
#include <iomanip>  // Pour std::setprecision
#include <climits>
#include <cmath>

ScalarConverter::ScalarConverter()
{    
}

void checklimits(std::string lit)
{
    
}

void ScalarConverter::convert(std::string lit)
{
    float f;
    int type;

    f = std::atof(lit.c_str());
    type = checkType(lit);
    std::cout << "type : " << type << std::endl;
    if (type == 0)
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "nan" << "f" << std::endl;
        std::cout << "double: "<< "nan" << std::endl;
        return ;
    }
    else if (type == 1)
    {
        std::cout << "char: " << lit << std::endl;
        std::cout << "int: " << static_cast<int>(lit.c_str()[0]) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(lit.c_str()[0]) << "f" << std::endl;
        std::cout << "double: "<< static_cast<double>(lit.c_str()[0]) << std::endl;
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
