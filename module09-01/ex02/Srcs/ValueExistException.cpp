#include "../Includes/ValueExistException.hpp"

ValueExistException::ValueExistException(std::string msg): m_msg(msg)
{

}

const char* ValueExistException::what() const throw()
{
    return m_msg.c_str();
}

ValueExistException::~ValueExistException() throw()
{
    
}