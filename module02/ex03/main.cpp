/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/06 08:43:16 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bsp.h"

int main( void ) {

bool test = false;
Fixed x(0.0f);
Fixed y(0.0f);
Point A(x, y);
A.toString();


Point ba(0.0f,10.0f);
Point B(ba);
B.toString();


Point C(10.0f,0.0f);
C.toString();
Point z(10.0f, 10.0f);
z.toString();
std::cout << "----------------" << std::endl;
test = bsp(A, B, C, z);
if (test)
    std::cout << "Point is inside the triangle" << std::endl;
else
    std::cout << "Point is outside the triangle" << std::endl;

return 0;
}
