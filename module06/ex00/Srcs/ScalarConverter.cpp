#include "../Includes/ScalarConverter.hpp"
#include "../Includes/colors.hpp"
#include <iomanip>  // Pour std::setprecision
#include <climits>
#include <cmath>
#include <cfloat>


bool checkChar(char c)
{
    if (isprint(c) == 0)
        return false;
    return true;
}

bool onlyDigits(std::string lit)
{
    for (size_t i = 0; i < lit.size(); ++i)
    {
        if (lit[i] < 48 || lit[i] > 57)
            return false;
    }
    return true;
}

bool isDigit(char c)
{
    return (!(c < 48 || c > 57));
}

bool isAFloat(const std::string &lit)
{
    int count = 0;

    size_t i = 0;
    if (lit[i] == '-' || lit[i] == '+')
        i++; 

    if (!isdigit(lit[i]) && lit[i] != '.')
        return false;

    for (; i < lit.size(); ++i)
    {
        if (lit[i] == '.')
            count++;
        if (lit[i] == '.' && count > 1)
            return false;
        else if (!isdigit(lit[i]) && lit[i] != '.')
            return false;
    }
    return (count == 1);
}

int stringToInt(std::string lit)
{
    std::stringstream stream;
    int i;
    stream << lit;
    stream >> i;
    return i;
}

double stringToDouble(std::string lit)
{
    std::stringstream stream;
    double d;
    stream << lit;
    stream >> d;
    return d;
}

bool isDisplayable(int c)
{
    if (c < 33 || c > 126)
        return false;
    return true;
}

ScalarConverter::ScalarConverter()
{    
}


std::string ScalarConverter::getCharFromInt(int nb)
{
    
    char ch[1];
    if (isprint(nb))
    {
        char c = nb;
        ch[0] = c;
        std::string chs(ch);
        return "'"+chs+"'";
    }
    else 
        return "Non Displayable";
}
// 0 nan
// 1 char
// 2 int
// 3 float
// 4 double
void ScalarConverter::debugState(bool state)
{
    if (state)
        std::cout << "[  " << GREEN << "true" << RESET << "   ] : ";
    else
        std::cout << "[  " << RED << "false" << RESET << "  ] : ";
}


int ScalarConverter::checkType(std::string lit)
{
  (void) lit;
  return 0;
}

void ScalarConverter::printLimits()
{
    std::cout << "int max : " << INT_MAX << " - int min : " << INT_MIN << std::endl;
    std::cout << "float max : " << FLT_MAX << " - float min : " << FLT_MIN  << std::endl;
    std::cout << "double max : " << DBL_MAX << " - double min : " << DBL_MIN << std::endl;
}
void ScalarConverter::checklimits(std::string lit)
{
   (void) lit;
}



void ScalarConverter::convertChar(std::string lit)
{
    std::cout << "char: ";
    if (lit == "nan")
        std::cout << "impossible" << std::endl;
    else if(isDisplayable(stringToInt(lit)))
        std::cout << static_cast<char>(stringToInt(lit)) << std::endl;
    else
        std::cout << "non displayable" << std::endl;
}

void ScalarConverter::convert(std::string lit)
{
    ScalarConverter::convertChar(lit);
   
}

ScalarConverter::~ScalarConverter()
{
   
}
