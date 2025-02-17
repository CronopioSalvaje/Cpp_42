#pragma once

#include <exception>
#include <string>

class GenericException : public std::exception
{
    private:
        std::string message;
    public:
        GenericException(std::string msg);
        const char * what() const throw();
        ~GenericException() throw();
};