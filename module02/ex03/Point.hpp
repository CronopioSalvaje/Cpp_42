/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:37:57 by ls                #+#    #+#             */
/*   Updated: 2024/08/05 16:32:55 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"


class Point
{
private:
    const Fixed _x;
    Fixed altX;
    const Fixed _y;
    Fixed altY;
public:
    Point();
    Point(float x, float y);
    Point(Fixed const &a , Fixed const &b);
    Point& operator=(Point &point);
    const Fixed &getX(void) const;
    const Fixed &getY(void) const;
    void toString(void);

    ~Point();
};



#endif