#include "../Includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{    
}

void ScalarConverter::convert(std::string lit)
{
    std::cout << "char: "<< std::endl;
    std::cout << "int: " << std::atoi(lit.c_str()) << std::endl;
    std::cout << "float: "<< std::endl;
    std::cout << "double: "<< std::endl;

}

ScalarConverter::~ScalarConverter()
{
   
}
