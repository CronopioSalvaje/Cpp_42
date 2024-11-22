#include "../Includes/ScalarConverter.hpp"
#include "../Includes/colors.hpp"
#include <iomanip>  // Pour std::setprecision
#include <climits>

#include <cmath>
#include <cfloat>

#define INT_OVERFLOW 1
#define FLOAT_OVERFLOW 2
#define IMPOSSIBLE 4
#define TEST2 8

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

bool isDisplayable(int c)
{
    if (c < 32 || c > 126)
        return false;
    return true;
}

ScalarConverter::ScalarConverter()
{    
}


bool ScalarConverter::isAChar(std::string lit)
{
    if (lit.size() != 1)
       return false;
    char c = lit[0];
    if (isDisplayable(c) && (c < '0' || c > '9'))
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
    if (isAChar(lit))
    {
        *result = static_cast<int>(lit[0]);
        return true;
    }
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

void ScalarConverter::print_err(int mask)
{
    if (mask & INT_OVERFLOW)
        std::cout << "int: impossible" << std::endl;
    if (mask & FLOAT_OVERFLOW)
        std::cout << "float: impossible" << std::endl;
    if (mask & IMPOSSIBLE)
        std::cout << "double: impossible" << std::endl;
}

bool ScalarConverter::handleNan(std::string lit)
{

    if (lit == "nan" || lit == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (lit == "nanf" ? "nanf" : "nan") << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    return false;
}

bool ScalarConverter::handleInf(std::string lit)
{

    if (lit == "-inf" || lit == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (lit == "-inff" ? "-inff" : "-inf") << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }

    if (lit == "inf" || lit == "inff" || lit == "+inf" || lit == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << ((lit == "inff" || lit == "+inff" )? "+inff" : "+inf") << std::endl;
        std::cout << "double: +inf" << std::endl;
        return true;
    }
    return false;
}

std::string ScalarConverter::getIntFromDouble(double d_converted)
{
    std::stringstream ss;
    std::string result_str;
    if (d_converted > std::numeric_limits<int>::max() 
        || d_converted < std::numeric_limits<int>::min())
        ss << "impossible";
    else
    {
        ss << static_cast<int>(d_converted);
        ss >> result_str;
    }
    return (result_str);    
}

bool ScalarConverter::hasDecimalPart(float d_converted)
{
     float intPart = static_cast<float>(static_cast<long long>(d_converted));
        float fracPart = d_converted - intPart;
        
        // Utiliser une comparaison avec un epsilon
        const float epsilon =  0.0001;
        
        if (fracPart < epsilon && fracPart > -epsilon) 
            return false;
    return true;
}

std::string ScalarConverter::getFloatFromDouble(double d_converted)
{   
    std::stringstream ss;
    std::string result_str;

    if (d_converted > std::numeric_limits<float>::max() || d_converted < -std::numeric_limits<float>::max() - 1) {
        ss << "impossible";
    } else if (d_converted != 0.0 && 
             (d_converted < 0 ? -d_converted : d_converted) < std::numeric_limits<float>::min()) {
        ss << "impossible";
    } else {
        //long long f_converted = static_cast<float>(d_converted);
        if (!hasDecimalPart(static_cast<float>(d_converted)))
            ss << std::fixed << std::setprecision(1) << static_cast<float>(d_converted) << "f";
        else
        {
            ss.unsetf(std::ios::fixed);
            ss.precision(6);
            ss << static_cast<float>(d_converted) << "f";

        }
    }
    ss >> result_str;
    return result_str;    
}

void ScalarConverter::convert(std::string lit)
{
    double d_converted = 0;
    int i_converted = 0;
    float f_converted = 0;

    if (handleNan(lit))
        return;
    if (handleInf(lit))
        return;
    ScalarConverter::convertChar(lit);
    if (!canConvertToDouble(lit,&d_converted))
    {
        if (canConvertToInt(lit, &i_converted))
        {
            std::cout << std::fixed << std::setprecision(1);
            f_converted = static_cast<float>(i_converted);
            d_converted = static_cast<double>(i_converted);
            std::cout << "int: " << i_converted << std::endl;
            std::cout << "float: " << f_converted << "f" << std::endl;
            std::cout << "double: " << d_converted << std::endl;
        }
        else
            ScalarConverter::print_err(INT_OVERFLOW | FLOAT_OVERFLOW | IMPOSSIBLE);
        return;
    }
    std::cout << "int: " << getIntFromDouble(d_converted) << std::endl;
    std::cout << "float: " << getFloatFromDouble(d_converted) << std::endl;
    if (d_converted == static_cast<double>(static_cast<int>(d_converted)))
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout.unsetf(std::ios::fixed);
        std::cout.precision(6);
    }
    std::cout << "double: " << d_converted << std::endl;
}

ScalarConverter::~ScalarConverter()
{
   
}
