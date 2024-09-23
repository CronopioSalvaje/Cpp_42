/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:14:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/23 11:07:40 by calbor-p         ###   ########.fr       */
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
    char c;
    bool hasChar = false;
    bool hasPoint = false;
    bool hasDigits = false;
    //bool onlydigits = true;
    int countChars = 0;
    for (int i = 0; lit.c_str()[i]; i++)
    {
        c = lit.c_str()[i];
        if (!hasDigits)
        hasDigits = isdigit(c) > 0 ? true : false;
        if (!hasPoint)
            hasPoint = c == '.' ? true : false;
        if (!hasChar)
            hasChar = isprint(c) > 0 ? true : false;
        countChars++;
    }
    if (hasChar && countChars == 1)
        return (1);
    if (!hasChar && !hasPoint)
        return (2);
    if (countChars > 1 && hasChar)
        return (0);
    if (hasPoint && !hasChar)
        return (4);
    return 0;
}