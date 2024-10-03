/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:32:24 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 14:36:05 by calbor-p         ###   ########.fr       */
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
        if (materia.materia[i] != NULL)
        {
            delete this->materia[i];
            this->materia[i] = materia.materia[i]->clone();
            std::cout <<  this->materia[i]->getType() << std::endl;            
        }
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
    for (int i = 0; i < MAX_ITEMS; i++)
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
        {
            delete this->materia[i];
            this->materia[i] = NULL;
        }
    }
    //std::cout << "MateriaSource is deleted" << std::endl;
}