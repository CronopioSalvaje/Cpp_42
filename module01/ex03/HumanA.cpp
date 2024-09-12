/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:52:33 by ls                #+#    #+#             */
/*   Updated: 2024/04/11 09:37:11 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):name(name), weapon(weapon)
{
    this->name = name;
    this->weapon = weapon;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}