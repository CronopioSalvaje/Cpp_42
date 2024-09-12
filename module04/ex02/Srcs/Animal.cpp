/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:57 by ls                #+#    #+#             */
/*   Updated: 2024/08/10 08:49:14 by ls               ###   ########.fr       */
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

std::string Animal::getType(void) const
{
    return this->_type;
}

