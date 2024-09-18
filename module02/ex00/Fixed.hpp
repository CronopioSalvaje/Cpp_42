/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:30 by ls                #+#    #+#             */
/*   Updated: 2024/09/16 15:25:02 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int integer;
    static const int fraction = 8;
public:
    Fixed();
    Fixed(Fixed &tc);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    void operator=(Fixed const &b);
    ~Fixed();
};


#endif