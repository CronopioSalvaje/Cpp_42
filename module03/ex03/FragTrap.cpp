/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:25:27 by ls                #+#    #+#             */
/*   Updated: 2024/09/19 11:20:17 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
{
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_name = name;
    this->_attackDamage = 30;
    this->_energyPoints = 100;
    this->_hitPoints = 100;
    std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const &cl): ClapTrap(cl)
{
    this->_attackDamage = cl._attackDamage;
    this->_energyPoints = cl._energyPoints;
    this->_hitPoints = cl._hitPoints;
    this->_name = cl._name;
    std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

void FragTrap::operator=(FragTrap const &cl)
{
    this->_attackDamage = cl._attackDamage;
    this->_energyPoints = cl._energyPoints;
    this->_hitPoints = cl._hitPoints;
    this->_name = cl._name;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0)
    {
        this->_energyPoints -= 1;
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;        
    }
    else 
    {
        std::cout << "FragTrap " << this->_name << " has no energy points to attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " high fives guys!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}