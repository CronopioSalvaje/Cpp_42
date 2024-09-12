/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:43:43 by ls                #+#    #+#             */
/*   Updated: 2024/04/11 09:44:23 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(std::string name);
        void attack(void);
        void setWeapon(Weapon &weapon);
};

#endif