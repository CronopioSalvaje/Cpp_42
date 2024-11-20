#include "../Includes/ScalarConverter.hpp"
#include "../Includes/colors.hpp"
#include <iomanip>  // Pour std::setprecision
#include <climits>
#include <limits>
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
    long int i;
    stream << lit;
    stream >> i;
    if (i > INT_MAX || i < INT_MIN)
        std::cout << "" << std::endl;
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
        return "non displayable";
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

bool ScalarConverter::isAChar(std::string lit)
{
    if (lit.size() != 1)
       return false;
    char c = lit[0];
    if (isDisplayable(c))
       return true;
    return false;

}


void ScalarConverter::convertChar(std::string lit)
{
    if (lit == "nan")
        std::cout << "char: impossible";
    else if(isDisplayable(stringToInt(lit)))
        std::cout << "char: '" << static_cast<unsigned char>(stringToInt(lit)) << "'";
    else if(isAChar(lit))
        std::cout << "char: '" << lit << "'";
    else
        std::cout << "char: non displayable";
    std::cout << std::endl;
}

bool ScalarConverter::canConvertToInt(std::string lit, int *result)
{
    std::stringstream stream(lit);
    stream >> *result;
    if (stream.fail())
        return false;
    std::string remain;
    stream >> remain;
    if (!remain.empty())
        return false;    

    if (*result == std::numeric_limits<int>::infinity() ||
        *result == -std::numeric_limits<int>::infinity()) {
        return false;
    }    
    return true;
}

bool ScalarConverter::canConvertToDouble(std::string lit, double *result)
{
    std::stringstream stream(lit);
    stream >> *result;
    if (stream.fail())
        return false;
    std::string remain;
    stream >> remain;
    if (!remain.empty())
        return false;    

    if (*result == std::numeric_limits<double>::infinity() ||
        *result == -std::numeric_limits<double>::infinity()) {
        return false;
    }    
    return true;
}

void ScalarConverter::convertInt(std::string lit)
{
    int result = 0;
    double dble_result = 0.0;
    std::cout << "int: ";
    if (lit == "nan")
        std::cout << "impossible";
    else if(isAChar(lit))
        std::cout << static_cast<int>(lit[0]);
    else if (canConvertToInt(lit, &result))
        std::cout << result;
    else
        std::cout << "overflow";
    std::cout << std::endl;
   /// regarder strtod -> avec errno et exceptions
}


void ScalarConverter::convert(std::string lit)
{
    ScalarConverter::convertChar(lit);
    ScalarConverter::convertInt(lit);
   
}

ScalarConverter::~ScalarConverter()
{
   
}
