/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/06 13:39:18 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"



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

   FragTrap frag("Frag");
   frag.highFivesGuys();
   frag.takeDamage(conan.getAttackDamage());
   frag.toString();
   return 0;
}

