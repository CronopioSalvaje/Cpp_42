/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:14:59 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/22 11:33:10 by calbor-p         ###   ########.fr       */
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