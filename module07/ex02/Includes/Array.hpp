/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:56:31 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 21:14:21 by calbor-p         ###   ########.fr       */
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


