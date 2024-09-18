/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:30 by ls                #+#    #+#             */
/*   Updated: 2024/09/18 15:18:39 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const &cl);
    void operator=(ScavTrap const &cl);
    void attack(const std::string& target);
    void toString(void);
    void guardGate();
    ~ScavTrap();
};


#endif