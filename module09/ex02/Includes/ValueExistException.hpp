#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <exception>

class ValueExistException : public std::exception
{
    private:
        char *msg = "Value already exist. All values must be different";
    public:
        const char* what() const throw();
};