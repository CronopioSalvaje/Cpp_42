/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:43:43 by ls                #+#    #+#             */
/*   Updated: 2024/04/11 09:36:48 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        void attack(void);
        void setWeapon(Weapon &weapon);
};

#endif