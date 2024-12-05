
#include "../Includes/Serializer.hpp"



Serializer::Serializer()
{
}

Serializer::~Serializer()
{
	
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t uintptr)
{
    return reinterpret_cast<Data*>(uintptr);
}
