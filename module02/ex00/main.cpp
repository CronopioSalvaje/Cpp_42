/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/16 15:25:25 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"


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
}


