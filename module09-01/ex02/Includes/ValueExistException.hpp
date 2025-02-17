#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class ValueExistException : public std::exception
{
    private:
        std::string m_msg;
        mutable std::string m_error;
    public:
        ValueExistException(std::string msg);
        const char* what() const throw();
        ~ValueExistException() throw();
};