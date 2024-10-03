/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:00:31 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "../Includes/Animal.hpp"
#include "../Includes/Dog.hpp"
#include "../Includes/Cat.hpp"
#include "../Includes/colors.hpp"
#include <ctime>
#include <sys/time.h>

int custom_rand(int min, int max)
{
   // LINEAR CONGRUENTIAL GENERATOR
   const unsigned long a = 1664525;    // Multiplicateur
   const unsigned long c = 1013904223; // Increment
   const unsigned long m = 4294967296; // Modulo (2^32)
   struct timeval time;
   gettimeofday(&time, NULL);   
   if (min >= max)
      throw std::out_of_range("min value must be inferior");
   time_t seed = time.tv_usec;
   seed = (a * seed + c) % m;
   int random = static_cast<int>(seed);
   random = min + (seed % (max - min + 1));
   return random;
}


void delete_animals(Animal *arr[], int max)
{
   for (int i = 0; i < max; i++)   
      delete arr[i];
      
}

int set_max(int ac, char **av)
{
   int max = 0;
   
   if (ac != 2)
      max = 5;
   else
   {
      try{
         max = std::atoi(av[1]);
         if (max < 1 || max > 100)
            throw std::out_of_range("Wrong value or out of range (1 - 100) - Value set to 5");
      }   
      catch(std::out_of_range &e){
         std::cout << e.what() << std::endl;
         max = 5;         
      }
   }
   return max;
}

void  setIdeas(Brain *br, std::string *ideas)
{
   int i = 0;
   (void) br;
   if (!br) {
      std::cerr << "Erreur : le pointeur Brain est nul !" << std::endl;
      return;
   }
   while(i < 18)
   {
      br->newIdea(ideas[i]);
      i++;
   }
}

void swapAnimals(Animal **a, Animal **b)
{
   Animal *temp = *a;
   *b = *a;
   *a = temp;   
}

void swapBrains(Brain **a, Brain **b)
{
   Brain *temp = *a;
   *b = *a;
   *a = temp;
}

void separator(void)
{
   std::cout << BLUE << "------------------------------" << RESET << std::endl << std::endl;
}

int main(int ac, char **av)
{
   int max = set_max(ac, av);
   std::string dogsIdeas[] = {"Waf !!", "want a bone", "Tired...", "I'm thirsty", "want to play with a ball", "play with me !!", "i'm bored", "this is my bone... get out of here", "i'm happy", "do you know were snoopy lives ?", "When does my master arrive ?", "starving...", "if i catch the pussy i'll eat it !!", "human are so strange", "you are so funny", "let's poo somewhere !", "i'm gonna catch this chicken and bury it", "why is this guy in my house ?"};
   std::string catsIdeas[] = {"Miaou !!", "want milk", "This is my sofa", "i'm sure there's a mouse somewhere", "someday i'll catch this fish", "you're my slave", "give me a hug", "i'll be back", "thoses curtains are too new... lets destroy them", "i hate you", "leave me alone", "MIAOOOOOOUUUU FFFFFFFFF", "ahhhhhh", "this fish is delicious", "mouse mouse mouse mouse", "zzzzzzzzzzz", "you're so funny", "play with me"};
   
   Animal *arr[max];
   
   for (int i = 0; i < max; i++)
   {
      std::cout << i << " - ";
      if (i % 2 == 0)
      {
         arr[i] = new Dog();
         arr[i]->makeSound();
         setIdeas(static_cast<Dog *>(arr[i])->getBrain(), dogsIdeas);
         std::cout << static_cast<Dog *>(arr[i])->getIdea() << std::endl;
      }
      else
      {
         arr[i] = new Cat();
         arr[i]->makeSound();
         setIdeas(static_cast<Cat *>(arr[i])->getBrain(), catsIdeas);
         std::cout << static_cast<Cat *>(arr[i])->getIdea() << std::endl;
      }
      separator();
   }

   Dog *toto = new Dog(*(static_cast<Dog *>(arr[2])));   
   std::cout << toto->getIdea() << std::endl;
   separator();
   delete_animals(arr, max);
   delete toto;
   separator();
   Cat john;
   john.makeSound();
   setIdeas(john.getBrain(), catsIdeas);
   std::cout << john.getIdea() << std::endl;
   
   return 0;
}