/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:34:58 by ls                #+#    #+#             */
/*   Updated: 2024/08/07 22:06:20 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public ScavTrap, virtual public FragTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &cl);
        void operator=(DiamondTrap const &cl);
        void attack(const std::string& target);
        void toString(void);
        void whoAmI(void);
        ~DiamondTrap(); 
};