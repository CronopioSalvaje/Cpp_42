/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/08/08 08:54:08 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


int main()
{
   const Animal* meta = new Animal();
   const Animal* j = new Dog();
   const Animal* i = new Cat();   

   std::cout << j->getType() << " " << std::endl;
   std::cout << i->getType() << " " << std::endl;
   i->makeSound(); //will output the cat sound!
   j->makeSound();
   meta->makeSound();
   delete i;
   delete j;
   delete meta;
   
   
   WrongAnimal *felix = new WrongCat();
   WrongAnimal *weird = new WrongAnimal();

   std::cout << "Hello ! I'm a " << felix->getType() << " : " ;
   felix->makeSound();
   std::cout << "Hello ! I'm a " << weird->getType() << " : " ;
   weird->makeSound();

   delete(felix);
   delete(weird);



   return 0;
}