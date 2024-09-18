/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/18 07:56:36 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bsp.h"

void in_the_triangle(bool test)
{
    std::cout << (test ? "Point is inside the triangle" 
        : "Point is outside the triangle") << std::endl;
  
}

int main( void ) {


std::cout << "Triangle ABC" << std::endl;
Fixed x(0.0f);
Fixed y(0.0f);
Point A(x, y);
std::cout << "A : ";
A.toString();

Point ba(0.0f,10.0f);
Point B(ba);
std::cout << "B : ";
B.toString();

Point C(10.0f,0.0f);
std::cout << "C : ";
C.toString();
std::cout << "----------------" << std::endl;

Point z(10.0f, 10.0f);
std::cout << "Z : ";
z.toString();
in_the_triangle(bsp(A, B, C, z));
std::cout << "J : ";
Point j(1.0f,1.0f);
j.toString();
in_the_triangle(bsp(A, B, C, j));

Point h(-12.0f, -3.2f);
std::cout << "H : ";
h.toString();
in_the_triangle(bsp(A, B, C, h));

return 0;
}
