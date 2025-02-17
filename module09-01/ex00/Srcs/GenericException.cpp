#include "../Includes/GenericException.hpp"

GenericException::GenericException(std::string msg): message(msg)
{    
}

const char *GenericException::what() const throw()
{
    return (message.c_str());
}

GenericException::~GenericException() throw() {}