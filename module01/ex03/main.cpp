/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/16 07:49:55 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

   /*
   Fichiers à rendre : Weapon.{h, hpp}, Weapon.cpp,
HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp
   */

int main()
{
   {
      Weapon club = Weapon("crude spiked club");
      HumanA bob("Bob", club);
      bob.attack();
      club.setType("some other type of club");
      bob.attack();
   }
   {
      Weapon club = Weapon("crude spiked club");
      HumanB jim("Jim");
      jim.attack();
      jim.setWeapon(club);
      jim.attack();
      club.setType("some other type of club");
      jim.attack();
   }
   return 0;
}
