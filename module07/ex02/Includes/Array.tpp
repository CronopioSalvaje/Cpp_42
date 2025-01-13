/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:13:32 by calbor-p          #+#    #+#             */
/*   Updated: 2025/01/13 19:45:01 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array():elements(NULL), length(0)
{
}

template<typename T>
Array<T>::Array(unsigned int length): length(length)
{
    elements = new T[length];
}

template<typename T>
Array<T>::Array(const Array<T> &arr)
{
    this->elements = NULL;
    this->length = 0; 
    *this = arr;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &arr) {
    if (this != &arr) {
        T *temp = new T[arr.length];
        for(size_t i = 0; i < arr.length; i++) {
            temp[i] = arr.elements[i];
        }
        if (this->elements)
            delete[] this->elements;
        elements = temp;
        length = arr.length;
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