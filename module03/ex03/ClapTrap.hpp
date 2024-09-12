/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 09:58:18 by ls                #+#    #+#             */
/*   Updated: 2024/08/07 21:22:20 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

class ClapTrap
{
    //private:
    
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &cl);
        ~ClapTrap();
        void operator=(ClapTrap const &cl);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // getters
        std::string getName(void) const; 
        unsigned int getHitPoints(void) const; 
        unsigned int getEnergyPoints(void) const; 
        unsigned int getAttackDamage(void) const;
        // setters
        void setName(std::string name); 
        void setHitPoints(unsigned int value); 
        void setEnergyPoints(unsigned int value); 
        void setAttackDamage(unsigned int value); 
        void toString(void);

};

#endif
