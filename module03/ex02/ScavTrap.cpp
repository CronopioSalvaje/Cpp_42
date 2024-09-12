/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:49:01 by ls                #+#    #+#             */
/*   Updated: 2024/08/06 13:32:46 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cl): ClapTrap(cl)
{
    std::cout << "ScavTrap constructor called for " << cl.getName() << std::endl;
}

void ScavTrap::operator=(ScavTrap const &cl)
{
    this->setName(cl.getName());
    this->setHitPoints(cl.getHitPoints());
    this->setEnergyPoints(cl.getEnergyPoints());
    this->setAttackDamage(cl.getAttackDamage());
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() > 0)
    {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;        
    }
    else 
    {
        std::cout << "ScavTrap " << this->getName() << " has no energy points to attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::toString(void)
{
    std::cout << "ScavTrap ";
    ClapTrap::toString();
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed" << std::endl;
}