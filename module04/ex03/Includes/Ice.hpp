/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:17:20 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 15:22:03 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "global.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : virtual public AMateria
{
    private :
    
    public : 
        Ice(void);
        Ice(std::string type);
        Ice(Ice const & ice);
        Ice &operator=(Ice const ice);
        void use(ICharacter& target);
        Ice *clone() const;
        ~Ice(void);
    
};

#endif