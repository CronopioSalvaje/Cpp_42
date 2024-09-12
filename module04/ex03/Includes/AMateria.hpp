/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:16:35 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 18:18:24 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;

#include "global.hpp"
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(AMateria const & materia);
        AMateria &operator=(AMateria const & materia);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
        virtual ~AMateria();
};

#endif
