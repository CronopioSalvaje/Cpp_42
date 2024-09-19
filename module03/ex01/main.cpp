/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/19 11:01:49 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"



int main( void )
{

   ScavTrap yoo("yooo");
   yoo.guardGate();
   ClapTrap doctor("doctor");
   ScavTrap warrior("warrior");

   ScavTrap clone = warrior;

   for(int i = 0; i < 10 ; i++)
   {
      yoo.attack("warrior");
      warrior.takeDamage(yoo.getAttackDamage());
      doctor.attack("yoo");
      yoo.takeDamage(doctor.getAttackDamage());
      warrior.attack("yoo");
      yoo.takeDamage(warrior.getAttackDamage());
      if (i % 2 == 0)
        warrior.beRepaired(1);
   }
   
   std::cout << "Warrior : energy " << warrior.getEnergyPoints() << std::endl;
   std::cout << "Warrior clone : energy " << clone.getEnergyPoints() << std::endl;

   return 0;
}
