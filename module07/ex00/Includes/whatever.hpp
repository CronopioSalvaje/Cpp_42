/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:59:47 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 18:08:41 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T &a, T &b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif


