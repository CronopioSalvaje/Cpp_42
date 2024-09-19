/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:24:05 by ls                #+#    #+#             */
/*   Updated: 2024/09/19 22:38:55 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "global.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria *inventary[4];
        int equiped;
        AMateria **old;
        int unequiped;
        void init_character(void);
        void addToOld(AMateria *m);
        void updateInventaryCount(void);
        AMateria **copyArray(AMateria **old, int size);
    public:
        Character();
        Character(std::string name);
        Character(Character const & c); // a la fin quand je saurais tout ce qu'il faut copier
        Character &operator=(Character const & c); // a la fin quand je saurais tout ce qu'il faut copier
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        ~Character();
};

#endif