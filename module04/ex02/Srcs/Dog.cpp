/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:30:18 by ls                #+#    #+#             */
/*   Updated: 2024/08/10 08:54:38 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Animal.hpp"
#include "../Includes/Dog.hpp"

Dog::Dog()
{
    this->brain = new Brain();
    this->_type = "Dog";
    std::cout << "i'm a new Dog" << std::endl;
}

Dog::Dog(Dog const &cl): Animal("Dog")
{
    this->brain = new Brain(*cl.brain);
    *this = cl;
    std::cout << "i'm a new Dog Clone" << std::endl;
}

void Dog::setIdea(std::string &idea)
{
    this->brain->newIdea(idea);
}

Brain *Dog::getBrain()
{
    return this->brain;
}

std::string Dog::getIdea(void)
{
    return this->brain->getIdea();
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::operator=(Dog const &cl)
{
    this->_type = cl._type;
    delete this->brain;
    this->brain = new Brain(*cl.brain);
}

void Dog::makeSound(void) const
{
    std::cout << "Waf waf  !! Waf waf !! " << std::endl;
}