/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:40:31 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 08:31:26 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/*(y2​−y1​)x−(x2​−x1​)y+(x2​y1​−x1​y2​)*/

Fixed crossProduct(Point const A, Point const B, Point const z)
{
    return (B.getY() - A.getY()) * z.getX() - (B.getX() - A.getX()) * z.getY() + (B.getX() * A.getY() - A.getX() * B.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if (crossProduct(a, b, point) <= 0 || crossProduct(b, c, point) <= 0 || crossProduct(c, a, point) <= 0)
        return false;
    return true;
}