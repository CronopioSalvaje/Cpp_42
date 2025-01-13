/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:56:31 by calbor-p          #+#    #+#             */
/*   Updated: 2025/01/13 19:26:16 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include "OutOfRangeException.hpp"

template<typename T>
class Array
{
    private   :
        T *elements;
        unsigned int length;
    public  :
        Array();
        Array(unsigned int length);
        Array(const Array<T> &arr);      
        Array<T> &operator=(const Array<T> &arr); 
        const T &operator[](size_t index) const
        {
            if (index >= length)
                throw OutOfRangeException("out of range");
            return elements[index];
        }

        T &operator[](size_t index)
        {
            if (index >= length)
                throw OutOfRangeException("out of range");
            return elements[index];
        }
        unsigned int size();        
        ~Array();
};

#include "Array.tpp"

#endif


