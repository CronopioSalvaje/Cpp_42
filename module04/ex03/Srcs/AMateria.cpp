/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:29:47 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 17:59:40 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/global.hpp"
#include "../Includes/AMateria.hpp"

AMateria::AMateria():type("unknown type")
{    
}

AMateria::AMateria(std::string const & type) :type(type)
{    
}

AMateria::AMateria(AMateria const & materia)
{
    this->type = materia.type;
}

AMateria &AMateria::operator=(AMateria const & materia)
{
    this->type = materia.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria::~AMateria()
{
   // std::cout << "AMateria " << this->type << " Destroyed" << std::endl;
}