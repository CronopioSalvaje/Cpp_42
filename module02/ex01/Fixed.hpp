/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:30 by ls                #+#    #+#             */
/*   Updated: 2024/08/02 22:35:35 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int integer;
    static const int fraction = 8;
public:
    Fixed();
    Fixed(Fixed const &tc);
    Fixed(int integer);
    Fixed(float fl);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    void operator=(Fixed const &b)
    {        
        std::cout << "Copy assignment operator called" << std::endl;
        this->integer = b.getRawBits();
    }
    ~Fixed();    
};

std::ostream &operator<<(std::ostream &print, Fixed const &nbr);
#endif
