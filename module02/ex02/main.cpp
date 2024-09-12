/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/05 10:32:52 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"


int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl; // 0
std::cout << ++a << std::endl; // 0.00390625
std::cout << a << std::endl; // 0.00390625
std::cout << a++ << std::endl; // 0.00390625
std::cout << a << std::endl; // 0.0078125


std::cout << b << std::endl; // 
std::cout << Fixed::max(a, b) << std::endl; // 

Fixed const c( Fixed( 5.05f ) + Fixed( 2.15f ) );
std::cout << c << std::endl;
Fixed const d( Fixed( 5.0f ) - Fixed( 2.50f ) );
std::cout << d << std::endl;
Fixed e( Fixed( 5.0f ) / Fixed( 2 ) );
std::cout << e << std::endl;
std::cout << std::endl;


e += e;
std::cout << e << std::endl;
e -= e/2;
std::cout << e << std::endl;
e *= e;
std::cout << e << std::endl;
e /= e;
std::cout << e << std::endl;
std::cout << std::endl;
std::cout << std::endl;


std::cout << "a is inferior than b" << std::endl;
std::cout << "a : "<< a << "  -b : " << b << std::endl;
std::cout << "tested : >  " << ((a > b) ? "true" : "false") << std::endl;
std::cout << "tested : >= " << ((a >= b) ? "true" : "false") << std::endl;
std::cout << "tested : == " << ((a == b) ? "true" : "false") << std::endl;
std::cout << "tested : != " << ((a != b) ? "true" : "false") << std::endl;
std::cout << "tested : < " << ((a < b) ? "true" : "false") << std::endl;
std::cout << "tested : <= " << ((a <= b) ? "true" : "false") << std::endl;
std::cout << std::endl;

std::cout << "a is superior than b" << std::endl;
a.setRawBits(250);
std::cout << "a : "<< a << "  - b : " << b << std::endl;
std::cout << "tested : >  " << ((a > b) ? "true" : "false") << std::endl;
std::cout << "tested : >= " << ((a >= b) ? "true" : "false") << std::endl;
std::cout << "tested : == " << ((a == b) ? "true" : "false") << std::endl;
std::cout << "tested : != " << ((a != b) ? "true" : "false") << std::endl;
std::cout << "tested : < " << ((a < b) ? "true" : "false") << std::endl;
std::cout << "tested : <= " << ((a <= b) ? "true" : "false") << std::endl;
std::cout << std::endl;


std::cout << "a is equal than b" << std::endl;
a = b;
std::cout << "a : "<< a << "  -b : " << b << std::endl;
std::cout << "tested : >  " << ((a > b) ? "true" : "false") << std::endl;
std::cout << "tested : >= " << ((a >= b) ? "true" : "false") << std::endl;
std::cout << "tested : == " << ((a == b) ? "true" : "false") << std::endl;
std::cout << "tested : != " << ((a != b) ? "true" : "false") << std::endl;
std::cout << "tested : < " << ((a < b) ? "true" : "false") << std::endl;
std::cout << "tested : <= " << ((a <= b) ? "true" : "false") << std::endl;
std::cout << std::endl;

Fixed m(8388607);
std::cout << "m : " << m << std::endl; 
Fixed n(-8388608);
std::cout << "n : "<< n << std::endl; 
Fixed z(8388608);
std::cout << "z : " << z << std::endl; 
Fixed y(-8388609);
std::cout << "y : " << y << std::endl;

return 0;
}
