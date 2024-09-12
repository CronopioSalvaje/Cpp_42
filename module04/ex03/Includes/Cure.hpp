/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:17:10 by ls                #+#    #+#             */
/*   Updated: 2024/08/16 15:21:44 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "global.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : virtual public AMateria
{
    private :
    public : 
        Cure();
        Cure(std::string type);
        Cure *clone() const;
        Cure(Cure const & cure);
        void use(ICharacter& target);
        Cure &operator=(Cure const cure);
        ~Cure(void);
    
};


#endif