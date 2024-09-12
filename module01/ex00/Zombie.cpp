/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:17:35 by calbor-p          #+#    #+#             */
/*   Updated: 2024/04/10 09:31:58 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
   this->name = name; 
}

void Zombie::announce(void)
{
    Zombie::print_name();
    std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::print_name(void)
{
    std::cout << this->name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " killed by a lonely knight !!" << std::endl;
}