/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:30 by ls                #+#    #+#             */
/*   Updated: 2024/09/19 11:52:24 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    FragTrap(void);    
public:
    FragTrap(std::string name);
    FragTrap(FragTrap const &cl);
    void operator=(FragTrap const &cl);
    void attack(const std::string& target);
    void highFivesGuys(void);
    ~FragTrap();
};


#endif