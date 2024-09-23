/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/23 12:11:08 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define line std::cout << std::endl
#define linex2 line; line

int main( void )
{
   std::cout << "Creation : "; line;
   std::cout << "-----------"; line;
   DiamondTrap maceo("Maceo");   
   line;
   DiamondTrap maceo2(maceo);
   line;
   DiamondTrap maceo3 = maceo;
   line;
   std::cout << "DiamondTrap tests ____________" << std::endl << std::endl;
   maceo.whoAmI();
   maceo.attack("Conan");
   maceo.attack("Conan");
   line;
   maceo2.whoAmI();
   maceo2.attack("Conan");
   line  ;
   maceo3.whoAmI();
   maceo3.guardGate();
   maceo3.highFivesGuys();
   line;

    std::cout << "Maceo : energy points : " << maceo.getEnergyPoints()
   << " - hit points : " << maceo.getHitPoints() << std::endl;
    std::cout << "Maceo2 : energy points : " << maceo2.getEnergyPoints()
   << " - hit points : " << maceo2.getHitPoints() << std::endl;
    std::cout << "Maceo3 : energy points : " << maceo3.getEnergyPoints()
   << " - hit points : " << maceo3.getHitPoints() << std::endl;
   
   std::cout << "DiamondTrap tests end____________" << std::endl << std::endl;
   
   line;
   return 0;
}

