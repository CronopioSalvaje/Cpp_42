/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:40:31 by ls                #+#    #+#             */
/*   Updated: 2024/09/18 07:33:00 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed crossProduct(Point const A, Point const B, Point const z)
{
    return (B.getY() - A.getY()) * z.getX() - (B.getX() - A.getX()) * z.getY() + (B.getX() * A.getY() - A.getX() * B.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool seg_abz = crossProduct(a, b, point) > 0;
    bool seg_bcz = crossProduct(b, c, point) > 0;
    bool seg_caz = crossProduct(c, a, point) > 0;
    return (seg_abz && seg_bcz && seg_caz);
}
