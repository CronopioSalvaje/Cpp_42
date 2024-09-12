/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 08:25:10 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 08:25:45 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_H
#define BSP_H

#include "Point.hpp"
#include "Fixed.hpp"

Fixed crossProduct(Point const A, Point const B, Point const z);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif