#include "../Includes/InvalidExpressionException.hpp"

InvalidExpressionException::InvalidExpressionException(std::string const &msg): m_msg(msg)
{
    m_error = "Invalid Expression : ";
}

const char * InvalidExpressionException::what() const throw()
{
    m_error += m_msg;
    return m_error.c_str();
}

InvalidExpressionException::~InvalidExpressionException() throw()
{}
