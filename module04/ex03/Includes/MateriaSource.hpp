/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:59:37 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 14:11:59 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "global.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private : 
        AMateria *materia[MAX_ITEMS];
        void initMateria(void);
    public :
        MateriaSource();
        MateriaSource(MateriaSource const & materia);
        MateriaSource &operator=(MateriaSource const & materia);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        ~MateriaSource();    
    
};

#endif