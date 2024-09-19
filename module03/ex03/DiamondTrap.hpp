/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:34:58 by ls                #+#    #+#             */
/*   Updated: 2024/09/19 12:09:21 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
    private:
        std::string _name;
        DiamondTrap(void);
    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &cl);
        void operator=(DiamondTrap const &cl);
        void attack(const std::string& target);
        void whoAmI(void);
        ~DiamondTrap(); 
};