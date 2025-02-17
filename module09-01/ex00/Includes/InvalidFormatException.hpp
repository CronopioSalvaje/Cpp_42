#pragma once

#include <exception>
#include <string>

class InvalidFormatException : public std::exception
{
    private:
        std::string message;
    public:
        InvalidFormatException(std::string msg);
        const char * what() const throw();
        ~InvalidFormatException() throw();
};