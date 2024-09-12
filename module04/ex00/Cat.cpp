/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:07 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:43:20 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
}

Cat::Cat(Cat const &cl): Animal("Cat")
{
    *this = cl;
}

Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
}

void Cat::operator=(Cat const &cl)
{
    this->_type = cl._type;
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou  !! Miaou !! " << std::endl;
}