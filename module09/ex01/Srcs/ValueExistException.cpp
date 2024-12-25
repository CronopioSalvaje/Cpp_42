#include "../Includes/ValueExistException.hpp"

const char* ValueExistException::what() const throw()
{
    return (msg);
}