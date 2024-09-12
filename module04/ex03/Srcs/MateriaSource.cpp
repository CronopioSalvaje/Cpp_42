/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:32:24 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 18:13:19 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/global.hpp"
#include "../Includes/MateriaSource.hpp"

void MateriaSource::initMateria(void)
{
    for (int i = 0; i < 4; i++)
    {
        this->materia[i] = NULL;
    }
}

MateriaSource::MateriaSource()
{    
    this->initMateria();
}
MateriaSource::MateriaSource(MateriaSource const & materia)
{
    this->initMateria();
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i] != NULL)
            delete this->materia[i];
        this->materia[i] = materia.materia[i];
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const & materia)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (this->materia[i] != NULL)
            delete this->materia[i];
        this->materia[i] = materia.materia[i];
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (this->materia[i] == NULL)
        {
            this->materia[i] = m;
            break;
        }   
                 
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->materia[i] != NULL)
        {
            if (this->materia[i]->getType() == type)
                return (this->materia[i]->clone());            
        }
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (this->materia[i] != NULL)
            delete this->materia[i];    
    }
    //std::cout << "MateriaSource is deleted" << std::endl;
}