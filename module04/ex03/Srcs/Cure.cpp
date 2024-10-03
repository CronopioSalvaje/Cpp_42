/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:19 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 14:38:28 by calbor-p         ###   ########.fr       */
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
    return (new Cure(this->type));
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
