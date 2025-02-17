#include "../Includes/FileErrorException.hpp"


FileErrorException::FileErrorException(std::string msg): message(msg)
{    
}
const char *FileErrorException::what() const throw()
{
    return (message.c_str());
}

FileErrorException::~FileErrorException() throw() {}