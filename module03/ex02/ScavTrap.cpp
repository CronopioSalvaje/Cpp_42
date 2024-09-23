/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:49:01 by ls                #+#    #+#             */
/*   Updated: 2024/09/23 11:45:33 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cl): ClapTrap(cl)
{
    std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}

void ScavTrap::operator=(ScavTrap const &cl)
{
    this->_attackDamage = cl._attackDamage;
    this->_energyPoints = cl._energyPoints;
    this->_hitPoints = cl._hitPoints;
    this->_name = cl._name;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0)
    {
        this->_energyPoints = this->_energyPoints - 1;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;        
    }
    else 
    {
        std::cout << "ScavTrap " << this->_name << " has no energy points to attack!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed" << std::endl;
}