/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:57 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 13:45:52 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
}


Animal::Animal(std::string const &type): _type(type)
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &cl)
{
    *this = cl;
}

void Animal::operator=(Animal const &cl)
{
    this->_type = cl._type;
}

void Animal::makeSound(void) const
{
    std::cout << "grrrrroooqmlkk" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

