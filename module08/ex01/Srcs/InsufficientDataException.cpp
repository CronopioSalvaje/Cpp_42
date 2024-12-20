#include "../Includes/InsufficientDataException.hpp"



const char* InsufficientDataException::what() const throw()
{
    return "Insufficient data";
}