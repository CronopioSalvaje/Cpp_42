#include "../Includes/WrongValueException.hpp"


WrongValueException::WrongValueException(std::string const &msg): m_msg(msg)
{
    m_error = "Wrong Value, ";
}

const char* WrongValueException::what() const throw()
{
    return (m_error + m_msg).c_str();
}

WrongValueException::~WrongValueException()throw() 
{    
}
