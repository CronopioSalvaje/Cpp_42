/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/19 11:45:01 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"



int main( void )
{

   std::cout << std::endl << "Create Scavtraps " << std::endl
            <<"------" << std::endl;
   ScavTrap yoo("yooo");
   ScavTrap yoo1(yoo);
   ScavTrap yoo2 = yoo;
   yoo2.guardGate();

   std::cout << std::endl << "Create FragTraps " << std::endl
            <<"------" << std::endl;
   FragTrap frag("Frag");
   FragTrap frag1(frag);
   FragTrap frag2 = frag;
   frag.highFivesGuys();

   std::cout << std::endl << std::endl;
   std::cout << "Fight ! " << std::endl
            <<"------" << std::endl;
   std::cout << "Fragtrap attack : "<< frag.getAttackDamage() << std::endl;
   std::cout << "Scavtrap attack : "<< yoo.getAttackDamage() << std::endl;
   
   /**
    * you and frag fight 2 turns
    */
   
   yoo.attack("frag");
   frag.takeDamage(yoo.getAttackDamage());
   frag.attack("yoo");
   yoo.takeDamage(frag.getAttackDamage());
   yoo.attack("frag");
   frag.takeDamage(yoo.getAttackDamage());
   frag.attack("yoo");
   yoo.takeDamage(frag.getAttackDamage());

   /**
    * you1 and frag1 fight 1 turns
    */

   yoo1.attack("frag");
   frag1.takeDamage(yoo1.getAttackDamage());
   frag1.attack("yoo1");
   yoo1.takeDamage(frag1.getAttackDamage());

   /**
    * you2 and frag2 don't fight !!! so clever moove !
    */
   
   std::cout << std::endl ;
   std::cout << std::endl << "Original " << std::endl
            <<"------" << std::endl;
   std::cout << "Frag  : energy points : " << frag.getEnergyPoints()
   << " - hit points : " << frag.getHitPoints() << std::endl;
   std::cout << "Yoo  : energy points : " << yoo.getEnergyPoints()
   << " - hit points : " << yoo.getHitPoints() << std::endl;
   
   std::cout << std::endl <<"Clone 1 " << std::endl
            <<"------" << std::endl;
   std::cout << "Frag clone 1 : energy points : " << frag1.getEnergyPoints()
   << " - hit points : " << frag1.getHitPoints() << std::endl;
   std::cout << "Yoo clone 1 : energy points : " << yoo1.getEnergyPoints()
   << " - hit points : " << yoo1.getHitPoints() << std::endl;
   
   std::cout << std::endl << "Clone 2 " << std::endl
            <<"------" << std::endl;
   std::cout << "Frag clone 2 : energy points : " << frag2.getEnergyPoints()
   << " - hit points : " << frag2.getHitPoints() << std::endl;
   std::cout << "Yoo clone 2 : energy points : " << yoo2.getEnergyPoints()
   << " - hit points : " << yoo2.getHitPoints() << std::endl;

   std::cout << std::endl << "Destroy" << std::endl
            <<"------" << std::endl;

   return 0;
}

