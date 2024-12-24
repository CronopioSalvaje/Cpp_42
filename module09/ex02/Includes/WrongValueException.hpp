#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class WrongValueException : public std::exception
{
    private:
        char *msg = "Wrong Value, unsigned int expected";
    public:
        const char* what() const throw();
};