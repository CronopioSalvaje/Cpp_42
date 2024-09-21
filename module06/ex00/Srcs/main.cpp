/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/09/21 22:18:47 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN "\033[32m"
#define DEFAULT_COLOR "\033[0m"

#include "../Includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    std::string toConvert(av[1]);
    ScalarConverter::convert(toConvert);
    
    return 0;
}
