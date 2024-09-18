/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/18 09:00:36 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"


int main( void ) {

/**
 * 
 * Suggested tests
 * 
 */
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl; // 0
std::cout << ++a << std::endl; // 0.00390625
std::cout << a << std::endl; // 0.00390625
std::cout << a++ << std::endl; // 0.00390625
std::cout << a << std::endl; // 0.0078125

std::cout << b << std::endl; // 

std::cout << Fixed::max(a, b) << std::endl; // 

std::cout << std::endl;
std::cout << std::endl;


/**
 * 
 * operations tests
 * 
 */

Fixed fix11( 5.05f );
Fixed fix12( 2.15f );
Fixed const c( fix11 + fix12);
std::cout << "addition : " << fix11 << " + " << fix12 << " = " << c << std::endl;
Fixed const d( fix11 - fix12);
std::cout << "substraction : " << fix11 << " - " << fix12 << " = " << d << std::endl;
Fixed fix21( 5.0f );
Fixed fix22( 2 );
Fixed e( fix21 / fix22 );
std::cout << "division : " << fix21 << " / " << fix22 << " = " << e << std::endl;
Fixed fix31( 5.0f );
Fixed fix32( 2 );
Fixed const f( fix31 * fix32);
std::cout << "multiplication : " << fix31 << " * " << fix32 << " = " << f << std::endl;

std::cout << "division : " << fix21 << "/= 0" << " = " << e << std::endl;
fix21 /= 0;

/**
 * 
 * +=, -=, /=, *= tests
 * 
 */


std::cout << std::endl;
std::cout << std::endl;
std::cout << "operator += : " << std::endl << e << " += " << e << " = ";
e += e;
std::cout << e << std::endl;
std::cout << "operator -= : " << std::endl << e << " -= " << e << "/2" << " = ";
e -= e/2;
std::cout << e << std::endl;
std::cout << "operator *= : " << std::endl << e << " *= " << e << " = ";
e *= e;
std::cout << e << std::endl;
std::cout << "operator /= : " << std::endl << e << " /= " << e << " = ";
e /= e;
std::cout << e << std::endl;
std::cout << std::endl;
std::cout << std::endl;

/**
 * 
 * comparisons tests
 * 
 */

std::cout << "a is inferior than b" << std::endl;
std::cout << "a : "<< a << " -> b : " << b << std::endl;
std::cout << "tested : >  " << ((a > b) ? "true" : "false") << std::endl;
std::cout << "tested : >= " << ((a >= b) ? "true" : "false") << std::endl;
std::cout << "tested : == " << ((a == b) ? "true" : "false") << std::endl;
std::cout << "tested : != " << ((a != b) ? "true" : "false") << std::endl;
std::cout << "tested : < " << ((a < b) ? "true" : "false") << std::endl;
std::cout << "tested : <= " << ((a <= b) ? "true" : "false") << std::endl;
std::cout << std::endl;

std::cout << "a is superior than b" << std::endl;
a.setRawBits(250);
std::cout << "a : "<< a << " -> b : " << b << std::endl;
std::cout << "tested : >  " << ((a > b) ? "true" : "false") << std::endl;
std::cout << "tested : >= " << ((a >= b) ? "true" : "false") << std::endl;
std::cout << "tested : == " << ((a == b) ? "true" : "false") << std::endl;
std::cout << "tested : != " << ((a != b) ? "true" : "false") << std::endl;
std::cout << "tested : < " << ((a < b) ? "true" : "false") << std::endl;
std::cout << "tested : <= " << ((a <= b) ? "true" : "false") << std::endl;
std::cout << std::endl;


std::cout << "a is equal than b" << std::endl;
a = b;
std::cout << "a : "<< a << " -> b : " << b << std::endl;
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
