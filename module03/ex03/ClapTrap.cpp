/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:58:31 by ls                #+#    #+#             */
/*   Updated: 2024/08/07 22:11:24 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("No name"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{    
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ClapTrap " << _name << " is created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cl) : _name(cl._name), _hitPoints(cl._hitPoints), _energyPoints(cl._energyPoints), _attackDamage(cl._attackDamage)
{    
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0)
    {
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;        
    }
    else 
    {
        std::cout << "ClapTrap " << _name << " has no energy points to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    if (this->_hitPoints > 0)
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        this->_hitPoints = 0;
    }
        
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}
        // setters
void ClapTrap::setName(std::string name)
{
    this->_name = name;
}
void ClapTrap::setHitPoints(unsigned int value)
{
    this->_hitPoints = value;
}
void ClapTrap::setEnergyPoints(unsigned int value)
{
    this->_energyPoints = value;
}
void ClapTrap::setAttackDamage(unsigned int value)
{
    this->_attackDamage = value;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0)
    {
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points!" << std::endl;        
    }
    else
        std::cout << "ClapTrap " << _name << " has no energy points to repair!" << std::endl;
}

void ClapTrap::operator=(ClapTrap const &cl)
{
    this->setAttackDamage(cl._attackDamage);
    this->setEnergyPoints(cl._energyPoints);
    this->setHitPoints(cl._hitPoints);
    this->setName(cl._name);
}

void ClapTrap::toString(void)
{
    std::cout << " - Attack Damage : " << this->getAttackDamage();
    std::cout << " - Hit Points " << this->getHitPoints() << " - Energy Points : " << this->getEnergyPoints() << std::endl;
}