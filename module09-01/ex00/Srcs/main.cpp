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

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <climits>
#include <vector>
#include "../Includes/BitcoinExchange.hpp"
#include "../Includes/FileErrorException.hpp"


int main(int ac, char **av)
{
    if (ac !=2)
    {
        std::cerr << RED << "Error: could not open file."
            << RESET << std::endl;
        return (1);
    }
    std::string path(av[1]);
    try{
        BitcoinExchange ex(path);
    }catch (FileErrorException &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

}