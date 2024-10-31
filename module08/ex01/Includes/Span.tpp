#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
void test_iterator(T &container, typename T::iterator it) {
    typename T::iterator end = container.end();
    try {
        if (it == end)
            throw std::out_of_range("Element not found");
        else
            std::cout << "value : " << *it << std::endl;
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
typename T::iterator easyfind(T &container, int occ) {
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it){
        if (*it == occ)
            return it;
    }
    return container.end();
};