/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:37:26 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 19:39:30 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), altX(0), _y(0), altY(0)
{
}

Point::Point(Fixed const &a , Fixed const &b): _x(a), altX(a), _y(b), altY(b)
{
}

Point::Point(float x, float y): _x(x), altX(x), _y(y), altY(y)
{
}

const Fixed &Point::getX(void) const
{
    return this->_x;
}



const Fixed &Point::getY(void) const
{
    return this->_y;
}

Point &Point::operator=(Point &point)
{   
    //this->altX = point.getX();
    //this->altY = point.getY();
    return point;
}

void Point::toString(void)
{
    std::cout << "x : " << this->_x.toFloat();
    std::cout << " - y : " << this->_y.toFloat() << std::endl;
}

Point::~Point()
{
}
