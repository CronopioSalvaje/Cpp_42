#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class WrongValueException : public std::exception
{
    private:
        std::string m_msg;
        mutable std::string m_error;
    public:
        WrongValueException(std::string const &msg);
        const char* what() const throw();
        virtual ~WrongValueException()throw();
};