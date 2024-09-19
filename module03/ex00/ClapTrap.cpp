/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:58:31 by ls                #+#    #+#             */
/*   Updated: 2024/09/19 10:19:02 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{    
    std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cl) : _name(cl._name), _hitPoints(cl._hitPoints), _energyPoints(cl._energyPoints), _attackDamage(cl._attackDamage)
{    
     std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0)
    {
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " 
        << this->_attackDamage << " points of damage!" << std::endl;        
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " has no energy points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints >= 0)
        this->_hitPoints -= amount;
    if (this->_hitPoints > 0)
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    else if (this->_hitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;        
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0)
    {
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points!" << std::endl;        
    }
    else
        std::cout << "ClapTrap " << this->_name << " has no energy points to repair!" << std::endl;
}

void ClapTrap::operator=(ClapTrap const &cl)
{
    this->_attackDamage = cl._attackDamage;
    this->_energyPoints = cl._energyPoints;
    this->_hitPoints = cl._hitPoints;
    this->_name = cl._name;
}
