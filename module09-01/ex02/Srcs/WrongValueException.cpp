#include "../Includes/WrongValueException.hpp"


WrongValueException::WrongValueException(std::string const &msg): m_msg(msg)
{
}

const char* WrongValueException::what() const throw()
{
    return m_msg.c_str();
}

WrongValueException::~WrongValueException()throw() 
{    
}
