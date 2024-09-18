/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:58:18 by ls                #+#    #+#             */
/*   Updated: 2024/09/18 15:14:40 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &cl);
        ~ClapTrap();
        void operator=(ClapTrap const &cl);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // getters
        std::string getName(void); 
        unsigned int getHitPoints(void); 
        unsigned int getEnergyPoints(void); 
        unsigned int getAttackDamage(void);
        // setters
        void setName(std::string name); 
        void setHitPoints(unsigned int value); 
        void setEnergyPoints(unsigned int value); 
        void setAttackDamage(unsigned int value); 
        void toString(void);

};

#endif
