/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:13:32 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 21:18:14 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
    elements = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int length): length(length)
{
    elements = new T[length];
}

template<typename T>
Array<T>::Array(T &arr)
{
    if (*this != arr)
        *this = arr;
}


template<typename T>
Array<T> &Array<T>::operator=(T &arr)
{
    if (this->elements)
        delete [] elements;
    length = arr.size();
    elements = new T[length];
    for(size_t i = 0; i < length; ++i)
    {
        this->elements[i] = arr[i];
    }
    return *this;
}

template<typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template<typename T>
unsigned int Array<T>::size()
{
    return length;
}