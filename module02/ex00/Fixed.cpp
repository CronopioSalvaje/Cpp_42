/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:00 by ls                #+#    #+#             */
/*   Updated: 2024/08/02 21:42:35 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->integer = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &tc)
{
    std::cout << "Copy constructor called" << std::endl;
    this->integer = tc.getRawBits(); 
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->integer;
}
void Fixed::setRawBits( int const raw )
{  
    this->integer = raw;   
}