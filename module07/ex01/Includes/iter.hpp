/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:16:35 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 18:56:52 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void display(T &thing)
{
    std::cout << thing << " ";
}

template<typename T>
void add2(T &thing)
{
    thing += 2;
}

template<typename T>
void iter(T *array, size_t length, void (*f)(T&))
{
    for (size_t i = 0; i < length ; ++i)
    {
        f(array[i]);
    }
}


#endif


