/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:34:54 by ls                #+#    #+#             */
/*   Updated: 2024/09/18 15:55:00 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name")
{
    this->_name = "Doe";
    this->FragTrap::_hitPoints = 100;
    this->ScavTrap::_energyPoints = 50;
    this->ScavTrap::_attackDamage = 30;
    std::cout << "DiamondTrap constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->_name = name;
    this->FragTrap::_hitPoints = 100;
    this->ScavTrap::_energyPoints = 50;
    this->ScavTrap::_attackDamage = 30;
    std::cout << "DiamondTrap constructor called for " << name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name : " << this->_name << " - ClapTrap name : " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << _name << " is destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cl): ClapTrap(), ScavTrap(), FragTrap()
{
    *this = cl;
}
void DiamondTrap::operator=(DiamondTrap const &cl)
{
    this->_attackDamage = cl._attackDamage;
    this->_energyPoints = cl._energyPoints;
    this->_hitPoints = cl._hitPoints;
    this->_name = cl._name;
    this->ClapTrap::_name = cl.ClapTrap::_name;
}

void DiamondTrap::toString(void)
{
    std::cout << "DiamondTrap " << "My name is " << this->_name;
    ClapTrap::toString();
}