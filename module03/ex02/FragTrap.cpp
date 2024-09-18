/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:25:27 by ls                #+#    #+#             */
/*   Updated: 2024/09/18 15:15:19 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
    this->setAttackDamage(30);
    this->setEnergyPoints(100);
    this->setHitPoints(100);
    std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)  
{
    this->setAttackDamage(30);
    this->setEnergyPoints(100);
    this->setHitPoints(100);
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const &cl): ClapTrap(cl)
{
    std::cout << "FragTrap constructor called for " << cl.getName() << std::endl;
}

void FragTrap::operator=(FragTrap const &cl)
{
    this->setName(cl.getName());
    this->setHitPoints(cl.getHitPoints());
    this->setEnergyPoints(cl.getEnergyPoints());
    this->setAttackDamage(cl.getAttackDamage());
}

void FragTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() > 0)
    {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;        
    }
    else 
    {
        std::cout << "FragTrap " << this->getName() << " has no energy points to attack!" << std::endl;
    }
}

void FragTrap::toString(void)
{
    std::cout << "FragTrap ";
    ClapTrap::toString();
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getName() << " high fives guys!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}