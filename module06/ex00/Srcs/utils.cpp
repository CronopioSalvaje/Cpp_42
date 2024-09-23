/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:14:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/23 08:09:33 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/utils.hpp"

std::string getCharFromInt(int nb)
{
    
    char ch[1];
    if (isprint(nb))
    {
        char c = nb;
        ch[0] = c;
        std::string chs(ch);
        return "'"+chs+"'";
    }
    else 
        return "Non Displayable";
}
// 0 nan
// 1 char
// 2 int
// 3 float
// 4 double
int checkType(std::string lit)
{
    bool hasChar;
    bool hasPoint;
    bool hasDigits;
    int countDigits;
    for (char c:lit)
    {
        if (!hasDigits)
        hasDigits = isdigit(c) > 0 ? true : false;
        if (!hasPoint)
            hasPoint = c == '.' ? true : false;
        if (!hasChar)
            hasChar = isalnum(c) > 0 ? true : false;
        countDigits++;
    }
}