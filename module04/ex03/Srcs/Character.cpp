/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:12 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 18:15:19 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/global.hpp"
#include "../Includes/Character.hpp"

Character::Character(): name("no name")
{
    this->init_character();
}

Character::Character(std::string name): name(name)
{    
    this->init_character();
}

std::string const & Character::getName() const
{
    return this->name;
}
void Character::equip(AMateria* m)
{
    if (this->equiped < 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->inventary[i] == NULL)
            {
                this->inventary[i] = m;
                break;
            }            
        }
        this->updateInventaryCount();
    }
    else
        this->add_to_old(m);
}

void Character::unequip(int idx)
{
    if (idx < 4)
    {
        this->add_to_old(this->inventary[idx]);
        this->inventary[idx] = NULL;
        this->updateInventaryCount();
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < MAX_ITEMS)
    {
        this->inventary[idx]->use(target);
        this->unequip(idx);        
    }
}

Character::~Character()
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (this->inventary[i] != NULL)
            delete this->inventary[i];
    }
    for (int i = 0; i < this->unequiped; i++)
    {
        if (this->old[i] != NULL)
            delete this->old[i];
    }
    delete [] old;
}


// custom

void Character::updateInventaryCount(void)
{
    int equiped = 0;
    
    for (int i = 0; i < 4; i++)
    {
        if (this->inventary[i] != NULL)
            equiped++;
    }
    this->equiped = equiped;
}

void Character::init_character(void)
{
    this->equiped = 0;
    this->unequiped = 0;
    this->old = new AMateria* [1];
    this->old[0] = NULL;
    for (int i = 0; i < 4; i++)
    {
        this->inventary[i] = NULL;
    }
}

AMateria **Character::copy_array(AMateria **old, int size)
{
    AMateria **newArray =  new AMateria* [size + 1];
    
    for (int i = 0; i < size; i++)
        newArray[i] = old[i];
    return (newArray);
}

void Character::add_to_old(AMateria *m)
{
    AMateria **clone = NULL;
    std::cout << "this->unequiped " << this->unequiped << std::endl;
    if (this->old[0] == NULL)
    {
        this->old[0] = m;
        this->unequiped++;
    }
    else
    {
        clone = this->copy_array(this->old, this->unequiped);
        clone[this->unequiped] = m;
        delete [] this->old;
        this->old = clone;
        this->unequiped++;
    }
}