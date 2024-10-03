/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:02:31 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:02:33 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"
#include "../Includes/Cat.hpp"
#include <string>

Cat::Cat()
{
    this->brain = new Brain();
    this->_type = "Cat";
    std::cout << "i'm a new Cat" << std::endl;
}

Cat::Cat(Cat const &cl): Animal("Cat")
{
    this->brain = new Brain(*cl.brain);
    *this = cl;
    std::cout << "i'm a new Cat Clone" << std::endl;
}

void Cat::setIdea(std::string &idea)
{
    this->brain->newIdea(idea);
}

std::string Cat::getIdea(void)
{
    return this->brain->getIdea();
}

Brain *Cat::getBrain()
{
    return this->brain;
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat is destroyed" << std::endl;
}

void Cat::operator=(Cat const &cl)
{
    // clone the brain;
    this->_type = cl._type;
    delete this->brain;
    this->brain = new Brain(*cl.brain);
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou  !! Miaou !! " << std::endl;
}