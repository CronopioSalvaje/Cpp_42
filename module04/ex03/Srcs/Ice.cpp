/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:24 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 18:01:44 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/global.hpp"
#include "../Includes/Ice.hpp"

Ice::Ice(void): AMateria("ice")
{    
}

Ice::Ice(std::string type): AMateria(type)
{    
}

Ice::Ice(Ice const & ice) : AMateria(ice.type)
{
}

Ice &Ice::operator=(Ice const ice)
{
    this->type = ice.type;
    return (*this);
}

Ice *Ice::clone() const
{
    return new Ice(this->type);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}

Ice::~Ice(void)
{
//  std::cout << "Materia " << this->type << " destroyed" << std::endl;
}
