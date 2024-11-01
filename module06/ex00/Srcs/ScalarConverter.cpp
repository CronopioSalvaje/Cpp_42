#include "../Includes/ScalarConverter.hpp"
#include <iomanip>  // Pour std::setprecision
#include <climits>
#include <cmath>
#include <cfloat>
#include <sstream>

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
int ScalarConverter::checkType(std::string lit)
{
    char c;
    bool hasChar = false;
    bool hasPoint = false;
    bool hasDigits = false;
    bool onlydigits = true;
    int countChars = 0;
    for (int i = 0; lit.c_str()[i]; i++)
    {
        c = lit.c_str()[i];
        if (!hasDigits)
            hasDigits = isdigit(c) > 0 ? true : false;
        if (onlydigits)
            onlydigits = isdigit(c) > 0 ? true : false;
        if (!hasPoint)
            hasPoint = c == '.' ? true : false;
        if (!hasChar)
            hasChar = (isprint(c) > 0) ? true : false;
        countChars++;
    }
    if (hasChar && countChars == 1)
        return (1);
    if (onlydigits)
        return (2);
    if (countChars > 1 && hasChar)
        return (0);
    if (hasDigits && hasPoint)
        return (3);
    if (hasPoint && !hasChar)
        return (4);
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
   
}

void ScalarConverter::displayResults(std::string ch,std::string in,std::string fl,std::string db)
{
    std::cout << "char: " << ch << std::endl;
    std::cout << "int: " << in << std::endl;
    std::cout << "float: " << fl << "f" << std::endl;
    std::cout << "double: "<< db << std::endl;
}

void ScalarConverter::convert(std::string lit)
{
    float f;
    double d;
    int type;
    std::stringstream stream;
    stream << lit;  
    stream >> f;
    stream << lit;
    stream >> d;
    type = checkType(lit);
   // std::cout << "type : " << type << std::endl;
    if (type == 0)
    {
        displayResults("impossible", "impossible", "nan", "nan");
        return ;
    }
    else if (type == 1)
    {
        std::cout << "char: " << lit << std::endl;
        std::cout << "int: " << static_cast<int>(lit.c_str()[0]) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(f) << "f" << std::endl;
        std::cout << "double: "<< static_cast<double>(d) << std::endl;
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
