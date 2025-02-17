#pragma once

#include <exception>
#include <string>
#include <iostream>

class InvalidExpressionException : public std::exception
{
    private:
        std::string m_msg;
        mutable std::string m_error;
    public:
        InvalidExpressionException(std::string const &msg);
        const char * what() const throw();
        ~InvalidExpressionException() throw();


};