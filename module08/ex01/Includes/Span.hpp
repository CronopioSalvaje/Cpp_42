#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

template<typename T>
class Span
{
    private:
        unsigned int size;
        T* data;
        static unsigned int elements; 
    public:
        Span(unsigned int size):size(size)
        {
            data = new T[size];
        }

        Span(Span const &sp)
        {
            *this = sp;
        }

        T &operator[](size_t index)
        {
            return data[index];
        }

        Span &operator=(Span const &sp)
        {
            if (this != &sp)
            {
                size = sp.size;
                if (data)
                    delete[] data;
                data = new T[size];
                for (size_t i = 0; i < size; ++i)
                    data[i] = sp.data[i];
            }
            return *this;
        }
        void addNumber(unsigned int value);
        size_t shortestSpan();
        size_t longestSpan();
        ~Span()
        {
            delete [] data;
        };

};

#include "Span.tpp"

#endif