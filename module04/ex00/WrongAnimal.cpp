/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:57 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 13:47:42 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Wrong Animal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}


WrongAnimal::WrongAnimal(std::string const &type): _type(type)
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cl)
{
    *this = cl;
}

void WrongAnimal::operator=(WrongAnimal const &cl)
{
    this->_type = cl._type;
}
void WrongAnimal::makeSound(void) const
{
    std::cout << "wrooonnnng aaaaaanimallll sound !!!!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

