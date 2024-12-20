#include "../Includes/Span.hpp"
#include <stdexcept>
#include <numeric>

Span::Span(unsigned int size):size(size), elements(0), debug(false)
{
}

Span::Span(Span const &sp)
{
    *this = sp;
}

int &Span::operator[](size_t index)
{
    return data[index];
}

Span &Span::operator=(Span const &sp)
{
    if (this != &sp)
    {
        size = sp.size;
        debug = sp.debug;
        elements = sp.elements;      
        for (size_t i = 0; i < sp.elements; ++i)
            data.push_back(sp.data[i]);
    }
    return *this;
}

void Span::add(int value)
{
    if (elements == size)
        throw std::out_of_range("max reached ! impossible to add new elements");
    else
    {
        data.push_back(value);
        Span::elements++;
    }
}

void Span::setDebug(bool debugMode)
{
    debug = debugMode;
}

void Span::addNumber(int value)
{
    try
    {
       add(value);
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

size_t Span::getSize()
{
    return data.size();
}

size_t Span::getShortest()
{
    size_t shortest = ULONG_MAX;

    if (data.size() < 2)
        throw InsufficientDataException();
    std::vector<int> clone = data;
    std::vector<int> difference(data.size());
    std::sort(clone.begin(), clone.end());
    std::adjacent_difference(clone.begin(), clone.end(), difference.begin());
    difference.erase(difference.begin());
    shortest = static_cast<size_t>(*std::min_element(difference.begin(), difference.end()));
    return shortest;
}

size_t Span::shortestSpan()
{
    size_t shortest = ULONG_MAX;
    try
    {
        shortest = getShortest();
    }
    catch(const InsufficientDataException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return shortest;      
}

size_t Span::getLongest()
{
    size_t result = ULONG_MAX;
    if (data.size() < 2)
        throw InsufficientDataException();
    std::vector<int> clone = data;
    std::sort(clone.begin(), clone.end());
    if (clone.front() < 0)
    {
        size_t back = static_cast<size_t>(std::abs(clone.back()));
        size_t front = static_cast<size_t>(std::abs(clone.front()));
        result = back + front;
        return (result);
    }
    return (clone.back() - clone.front());        
}

size_t Span::longestSpan()
{
    size_t longest = ULONG_MAX;
    try
    {
        longest = getLongest();
    }
    catch(const InsufficientDataException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    return longest;      
}

void Span::debugSpan()
{
    if (debug)
    {
        std::cout << "debug span ------------------------" << std::endl;
        std::vector<int>::iterator it;
        for (it = data.begin(); it != data.end(); ++it)
            std::cout << *it << std::endl;
        std::cout << "------------------------ debug span" << std::endl;
    }
}

void Span::debugSpan(std::vector<int> d)
{
    if (debug)
    {
        std::cout << "debug span ------------------------" << std::endl;
        std::vector<int>::iterator it;
        for (it = d.begin(); it != d.end(); ++it)
            std::cout << *it << std::endl;
        std::cout << "------------------------ debug span" << std::endl;
    }
}

Span::~Span()
{
}