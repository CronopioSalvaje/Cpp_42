/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:07 by ls                #+#    #+#             */
/*   Updated: 2024/08/10 08:53:50 by ls               ###   ########.fr       */
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