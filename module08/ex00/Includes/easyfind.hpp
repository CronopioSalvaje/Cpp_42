#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

template<typename T>
void test_iterator(T &container, typename T::iterator it);


template<typename T>
typename T::iterator easyfind(T &container, int occ);

#include "easyfind.tpp"

#endif