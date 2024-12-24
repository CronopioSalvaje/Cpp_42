#pragma once

#include <iostream>
#include <stack>
#include <vector>

template <typename T>
class MutantStack: public std::stack<T>
{
    private:
    public:
        MutantStack();
        MutantStack(MutantStack &cl);
        MutantStack<T> &operator=(MutantStack &cl);
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        ~MutantStack();
    
        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

};
