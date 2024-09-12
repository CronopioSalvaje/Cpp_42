/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:19 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 18:01:40 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/global.hpp"
#include "../Includes/Cure.hpp"

Cure::Cure(): AMateria("cure")
{    
}

Cure::Cure(std::string type): AMateria(type)
{    
}

Cure *Cure::clone() const
{
    return new Cure(this->type);
}

Cure::Cure(Cure const & cure): AMateria(cure.type)
{    
}

Cure &Cure::operator=(Cure const cure)
{
    this->type = cure.type;
    return (*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() <<"’s wounds *" << std::endl;
}

Cure::~Cure(void)
{
   // std::cout << "Materia " << this->type << " destroyed" << std::endl;
}
