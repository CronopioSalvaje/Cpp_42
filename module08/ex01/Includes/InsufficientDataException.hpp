#pragma once

#include <iostream>
#include <exception>

class InsufficientDataException: public std::exception
{
    public:
        const char* what() const throw();
};
