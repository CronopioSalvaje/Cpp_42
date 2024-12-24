#include "../Includes/WrongValueException.hpp"

const char* WrongValueException::what() const throw()
{
    return (msg);
}