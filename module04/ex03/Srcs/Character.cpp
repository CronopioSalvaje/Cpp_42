/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:12 by ls                #+#    #+#             */
/*   Updated: 2024/09/19 22:36:04 by calbor-p         ###   ########.fr       */
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

Character::Character(Character const & c)
{   
    this->name = c.name;
    this->equiped = c.equiped;
    this->init_character();
    for (int i = 0; i < 4; i++)
    {
        if (c.inventary[i])
            this->inventary[i] = c.inventary[i]->clone();
        else
            this->inventary[i] = NULL;
    }

}

Character &Character::operator=(Character const & c)
{
    this->name = c.name;
    this->equiped = c.equiped;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventary[i])
        {
            delete(this->inventary[i]);
            this->inventary[i] = NULL;
        }
        if (c.inventary[i])
            this->inventary[i] = c.inventary[i]->clone();
        else
            this->inventary[i] = NULL;
    }
    return *this;
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
    {
        this->add_to_old(m);
    }
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
    if (idx >= MAX_ITEMS ||  this->inventary[idx] == NULL)
    {
        std::cout << this->name << " says : no materia stored here !!" << std::endl;
        return;
    }    
    if (idx >= 0 && idx < MAX_ITEMS)
    {
        if ( this->inventary[idx])
        {
            this->inventary[idx]->use(target);
            this->unequip(idx);            
        }
        else 
            std::cout << this->name << " says : no materia stored here !!" << std::endl;
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