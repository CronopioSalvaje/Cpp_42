/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/18 14:56:50 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"



int main( void )
{
   ClapTrap thor("Thor");
   ClapTrap conan(thor);
   conan.setName("Conan");
   ClapTrap joe = thor;  
   joe.setName("Joe");

   thor.attack("Conan");
   conan.takeDamage(2);
   joe.attack("conan");
   conan.takeDamage(2);
   conan.beRepaired(1);
   thor.toString();
   conan.toString();
   joe.toString();     

   ScavTrap Yoo("Yooo");
   Yoo.toString();
   Yoo.attack("Conan");
   Yoo.guardGate();
   
   ScavTrap doctor = Yoo;
   doctor.setName("Who");
   ScavTrap warrior(Yoo);
   warrior.setName("Hug");

   
   warrior.setEnergyPoints(2);
   doctor.setEnergyPoints(588);
   Yoo.setEnergyPoints(42);
   std::cout << "Warrior energy : " << warrior.getEnergyPoints() << std::endl;
   std::cout << "doctor energy : " << doctor.getEnergyPoints() << std::endl;
   std::cout << "Yoo energy : " << Yoo.getEnergyPoints() << std::endl;
   

   return 0;
}
