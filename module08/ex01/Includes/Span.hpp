#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <climits>
#include <algorithm>
#include "InsufficientDataException.hpp"

class Span
{
    private:
        unsigned int size;
        unsigned int elements; 
        std::vector<int> data;
        size_t getShortest();
        size_t getLongest();
        void add(int value);
        bool debug;
    public:
        size_t getSize();
        void setDebug(bool debugMode);
        void debugSpan(std::vector<int> d);
        void debugSpan();
        Span(unsigned int size);
        Span(Span const &sp);
        int &operator[](size_t index);
        template <typename IT>
        void addRange(IT begin, IT end)
        {
            IT it;
            for(it = begin; it !=end; ++it)
                addNumber(*it);
        }
        Span &operator=(Span const &sp);
        void addNumber(int value);
        size_t shortestSpan();
        size_t longestSpan();
        ~Span();

};

#include "Span.tpp"

#endif