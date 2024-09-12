/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/06 11:48:08 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.cpp"



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
   return 0;
}
