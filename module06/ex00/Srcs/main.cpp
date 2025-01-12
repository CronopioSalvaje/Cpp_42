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

#include "../Includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << BOLD_RED << "should have one literal C++ arg" << RESET << std::endl;
        return (1);
    }

    if (av[1])
    {
        std::string toConvert(av[1]);
        (void) toConvert;
        ScalarConverter::convert(toConvert);
    }

    return 0;
}
