/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:30:18 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:43:26 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
}

Dog::Dog(Dog const &cl): Animal("Dog")
{
    *this = cl;
}

Dog::~Dog()
{
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::operator=(Dog const &cl)
{
    this->_type = cl._type;
}

void Dog::makeSound(void) const
{
    std::cout << "Waf waf  !! Waf waf !! " << std::endl;
}