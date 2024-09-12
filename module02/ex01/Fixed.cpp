/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:00 by ls                #+#    #+#             */
/*   Updated: 2024/08/02 22:47:20 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed()
{
    this->integer = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &tc)
{
    std::cout << "Copy constructor called" << std::endl;
    this->integer = tc.getRawBits(); 
}

Fixed::Fixed(int integer) : integer(integer << this->fraction)
{
    std::cout << "Float integer called" << std::endl;
}
Fixed::Fixed(float fl) : integer(static_cast<int>(fl * (1 << this->fraction)))
{    
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->integer) / (1 << this->fraction);
}

int Fixed::toInt( void ) const
{
    return (int)this->integer >> this->fraction;
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

std::ostream &operator<<(std::ostream &print, Fixed const &nbr)
{
    return print << nbr.toFloat();
}
