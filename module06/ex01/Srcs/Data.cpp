
#include "../Includes/Data.hpp"

int Data::instance = 1;

Data::Data()
{
    id = Data::instance;
    Data::instance++;
}

Data::Data(Data const &cl)
{
    *this = cl;
}
Data &Data::operator=(Data const &cl)
{
    id = cl.id;
    return *this;
}

int Data::getId()
{
    return id;
}

Data::~Data()
{
	
}

