/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:30 by ls                #+#    #+#             */
/*   Updated: 2024/08/07 13:22:39 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    
public:
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &cl);
    void operator=(ScavTrap const &cl);
    void attack(const std::string& target);
    void toString(void);
    void guardGate();
    ~ScavTrap();
};


#endif