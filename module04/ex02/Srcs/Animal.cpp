/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:02:06 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:02:10 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"

int Animal::count = 0;

Animal::Animal()
{
}

Animal::Animal(std::string const &type): _type(type), id(count)
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

std::string Animal::getType(void) const
{
    return this->_type;
}

