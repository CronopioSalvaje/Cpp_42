/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 14:59:39 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/global.hpp"
#include "../Includes/IMateriaSource.hpp"
#include "../Includes/MateriaSource.hpp"
#include "../Includes/Ice.hpp"
#include "../Includes/Cure.hpp"
#include "../Includes/Character.hpp"
#include "../Includes/AMateria.hpp"

#define GREEN "\033[32m"
#define DEFAULT_COLOR "\033[0m"

void extraTests()
{
    std::cout << GREEN << "Create Characters" << DEFAULT_COLOR << std::endl;    
    ICharacter *Johnny = new Character("Johnny");
    ICharacter *Stan = new Character("Stan");
    Character Chris("Chris");
    
    Character Cricri = Chris;
    
    std::cout << GREEN << "Using inexistant Materia" << DEFAULT_COLOR << std::endl;  
    Johnny->use(0, *Stan);
    Stan->use(1, *Johnny);
    Chris.use(522, *Stan);

    
    std::cout << GREEN << "Create Materia Source src && src2" << DEFAULT_COLOR << std::endl;  
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    MateriaSource src2;
    src2.learnMateria(new Ice());
    src2.learnMateria(new Cure());
    
    
    AMateria *tmp;
    std::cout << GREEN << "Affecting Materias to Johnny" << DEFAULT_COLOR << std::endl;    
    tmp = src->createMateria("ice");  
      std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
    Johnny->equip(tmp);
    tmp = src->createMateria("ice");  
      std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
    Johnny->equip(tmp);
    tmp = src->createMateria("cure");  
      std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
    Johnny->equip(tmp);
    tmp = src->createMateria("cure");  
      std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
    Johnny->equip(tmp);
    Johnny->equip(tmp);
    
    /**
     * 
     * these ones should be unemployed... Character can only store 4 Materias
     */
    tmp = src->createMateria("cure");  
    Johnny->equip(tmp);


  std::cout << GREEN << "Johnny Use his Materias" << DEFAULT_COLOR << std::endl;    
    Johnny->use(12, *Stan); // Does not exist
    Johnny->use(0, *Stan);
    Johnny->use(1, *Stan);
    Johnny->use(2, *Stan);
    Johnny->use(3, *Stan);
    Johnny->use(0, *Stan); // Already Used
    
  std::cout << GREEN << "trying to refill materias and equip and unequip tests" << DEFAULT_COLOR << std::endl;   
  tmp = src2.createMateria("cure");  
  Johnny->equip(tmp);
  Johnny->unequip(0);
  Johnny->use(0, *Stan);
  
  tmp = src2.createMateria("ice"); 
  Johnny->equip(tmp);
  tmp = src2.createMateria("ice");
  Johnny->equip(tmp);
  tmp = src2.createMateria("ice"); 
  Johnny->equip(tmp);
  tmp = src2.createMateria("ice");
  Johnny->equip(tmp);

  Johnny->unequip(0);
  Johnny->unequip(1);
  Johnny->unequip(2);
  Johnny->unequip(3);
  Johnny->unequip(4);

  Johnny->use(1, *Stan);
  Johnny->use(2, *Stan);
  Johnny->use(3, *Stan);
  Johnny->use(0, *Stan);

  std::cout << GREEN << "Trying to clone Materia Source" << DEFAULT_COLOR << std::endl; 
  
  MateriaSource mat;
  mat = src2;
  
  std::cout << GREEN << "tests with clone" << DEFAULT_COLOR << std::endl; 
  tmp = mat.createMateria("ice");
  Chris.equip(tmp);
  tmp = mat.createMateria("cure");
  Chris.equip(tmp);
  tmp = mat.createMateria("fire");
  Chris.equip(tmp);

  Chris.use(0, *Stan);
  Chris.use(1, *Stan);
  Chris.use(2, *Stan);

  std::cout << GREEN << "tests with original" << DEFAULT_COLOR << std::endl; 

  tmp = src2.createMateria("ice");
  Chris.equip(tmp);
  tmp = src2.createMateria("cure");
  Chris.equip(tmp);
  tmp = src2.createMateria("fire");
  Chris.equip(tmp);

  Chris.use(0, *Stan);
  Chris.use(1, *Stan);
  Chris.use(2, *Stan);

  
  std::cout << GREEN << "Refill Chris's materia and compare with cloned Cricri" << DEFAULT_COLOR << std::endl;  
  tmp = src2.createMateria("ice");
  Chris.equip(tmp);
  tmp = src2.createMateria("cure");
  Chris.equip(tmp);
  tmp = src2.createMateria("ice");
  Chris.equip(tmp);
  tmp = src2.createMateria("cure");
  Chris.equip(tmp);

  Cricri.use(0, *Stan);
  Cricri.use(1, *Stan);
  Cricri.use(2, *Stan);
  Cricri.use(3, *Stan);

  Chris.use(0, *Stan);
  Chris.use(1, *Stan);
  Chris.use(2, *Stan);
  Chris.use(3, *Stan);

  Character gronk;
  std::cout << GREEN << "Refill Chris's materia and create gronk clone Cricri" << DEFAULT_COLOR << std::endl;  
  tmp = src2.createMateria("ice");
  Chris.equip(tmp);
  std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
  tmp = src2.createMateria("cure");
  Chris.equip(tmp);
  std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
  tmp = src2.createMateria("ice");
  Chris.equip(tmp);
  std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
  tmp = src2.createMateria("cure");
  std::cout << "test : " << tmp << " - Type : " << tmp->getType()<< std::endl;
  Chris.equip(tmp);

  gronk = Chris;

  std::cout << GREEN << "chris use his materias" << DEFAULT_COLOR << std::endl;  
  Chris.use(0, *Stan);
  Chris.use(1, *Stan);
  Chris.use(2, *Stan);
  Chris.use(3, *Stan);

 std::cout << GREEN << "gronks use his materias" << DEFAULT_COLOR << std::endl;  
  gronk.use(0, *Stan);
  gronk.use(1, *Stan);
  gronk.use(2, *Stan);
  gronk.use(3, *Stan);
  
  std::cout << GREEN << "Freeing memory" << DEFAULT_COLOR << std::endl;    
    delete Stan;
    delete Johnny;
    delete src;
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    extraTests();
    return 0;
}
