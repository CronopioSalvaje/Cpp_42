/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:13:32 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 19:32:52 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
}

template<typename T>
Array<T>::Array(unsigned int length)
{
    elements = new T[length];
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