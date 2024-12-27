#include "../Includes/ValueExistException.hpp"

ValueExistException::ValueExistException(std::string msg): m_msg(msg)
{
    m_error = "Value already exist: ";
}

const char* ValueExistException::what() const throw()
{
    return (m_error + m_msg).c_str();
}

ValueExistException::~ValueExistException() throw()
{
    
}