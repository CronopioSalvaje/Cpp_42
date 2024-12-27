/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/12/06 22:27:18 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/colors.hpp"
#include "../Includes/RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED << "Invalid Expression : Args expected" << std::endl;
        return (1);
    }
    std::string expr(av[1]);
    RPN exp(expr);
    return 0;
}