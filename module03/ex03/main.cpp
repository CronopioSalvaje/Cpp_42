/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/19 12:15:15 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define line std::cout << std::endl;
#define linex2 line line

int main( void )
{

   std::cout << "DiamondTrap tests ____________" << std::endl << std::endl;
   DiamondTrap maceo("Maceo");   
   maceo.whoAmI();
   maceo.attack("Conan");
   line
   DiamondTrap maceo2(maceo);
   maceo2.whoAmI();
   maceo2.attack("Conan");
   line   
   DiamondTrap maceo3 = maceo;
   maceo3.whoAmI();
   maceo3.attack("Conan");
   line
   std::cout << "DiamondTrap tests end____________" << std::endl << std::endl;
   
   return 0;
}

