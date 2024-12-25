#include "../Includes/InvalidFormatException.hpp"

InvalidFormatException::InvalidFormatException(std::string msg): message(msg)
{    
}

const char *InvalidFormatException::what() const throw()
{
    return (message.c_str());
}

InvalidFormatException::~InvalidFormatException() throw() {}