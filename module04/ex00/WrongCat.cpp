/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:07 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:48:59 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &cl): WrongAnimal("WrongCat")
{
    *this = cl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat is destroyed" << std::endl;
}

void WrongCat::operator=(WrongCat const &cl)
{
    this->_type = cl._type;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Miaou  !! Miaou !! " << std::endl;
}