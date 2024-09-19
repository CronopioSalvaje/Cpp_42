/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/19 10:23:22 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
   /**
    * Constructor with string name
    */
   ClapTrap thor("Thor");
   
   /**
    * Copie Constructor
    */
   ClapTrap thor2(thor);
   
   /**
    * Operator Overload
    */
   ClapTrap thor3 = thor;  
   

   ClapTrap conan("Conan");
   ClapTrap xena("Xena");
   
   for(int i= 0 ; i < 11; i++)
   {
      thor.attack("Conan");
      conan.takeDamage(1);
      if (i % 2 == 0)
         xena.takeDamage(1);
      else
         xena.beRepaired(1);
   }
   return 0;
}
