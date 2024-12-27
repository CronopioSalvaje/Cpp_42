#include "../Includes/utils.hpp"

std::string trim(std::string str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last =  str.find_last_not_of(" \t\n\r\f\v");
    
    if (first == std::string::npos)
        return "";
    return (str.substr(first, last - first + 1));
}


void toogle(bool *val)
{
    *val = !(*val);
}