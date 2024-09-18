/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:30 by ls                #+#    #+#             */
/*   Updated: 2024/09/18 15:07:50 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap const &cl);
        void operator=(FragTrap const &cl);
        void attack(const std::string& target);
        void toString(void);
        void highFivesGuys(void);
        ~FragTrap();
};


#endif