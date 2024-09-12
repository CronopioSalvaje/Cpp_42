/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/02 18:08:48 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

/*
int main( void )
{
   Fixed a;
   Fixed b(a);
   Fixed c;
   c = b;
   std::cout << a.getRawBits() << std::endl;
   std::cout << b.getRawBits() << std::endl;
   std::cout << c.getRawBits() << std::endl;

   b.setRawBits(50);
   std::cout << "valeur de b : " << b.getRawBits() << std::endl;
   a = b;
   std::cout << "valeur de a : " << a.getRawBits() << std::endl;
   b.setRawBits(20);
   std::cout << "valeur de b : " << b.getRawBits() << std::endl;
   std::cout << "valeur de a : " << a.getRawBits() << std::endl;

   Fixed o(b);
   b.setRawBits(30);
   std::cout << "valeur de b : " << b.getRawBits() << std::endl;
   std::cout << "valeur de o : " << o.getRawBits() << std::endl;
   
   
   return 0;
}*/


int main( void )
{
   Fixed a;
   Fixed const b( 10 );
   Fixed const c( 42.42f );
   /*Fixed const d( b );
   a = Fixed( 1234.4321f );
   std::cout << "a is " << a << std::endl;
   std::cout << "b is " << b << std::endl;
   std::cout << "c is " << c << std::endl;
   std::cout << "d is " << d << std::endl;
   std::cout << "a is " << a.toInt() << " as integer" << std::endl;
   std::cout << "b is " << b.toInt() << " as integer" << std::endl;
   std::cout << "c is " << c.toInt() << " as integer" << std::endl;
   std::cout << "d is " << d.toInt() << " as integer" << std::endl;*/
   return 0;
}
