/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:57 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 13:53:17 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"

int Animal::count = 0;

Animal::Animal(): id(count)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string const &type): _type(type), id(count)
{
    std::cout << "Animal constructor called" << std::endl;
}


Animal::Animal(Animal const &cl)
{
    *this = cl;
}

void Animal::operator=(Animal const &cl)
{
    this->_type = cl._type;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}
void Animal::makeSound(void) const
{
    std::cout << "grrrrroooqmlkk" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

