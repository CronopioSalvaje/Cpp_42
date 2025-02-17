#pragma once

#include <exception>
#include <string>

class FileErrorException : public std::exception
{
    private:
        std::string message;
    public:
        FileErrorException(std::string msg);
        const char * what() const throw();
        ~FileErrorException() throw();
};