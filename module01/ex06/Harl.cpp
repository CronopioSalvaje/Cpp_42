/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:31:50 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/12 22:02:17 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
 	<< " enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	std::string warnings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*message[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};	
	switch(this->filter)
	{
		case 0: i = 0; break;
		case 1: i = 1; break;
		case 2: i = 2; break;
		case 3: i = 3; break;
		default : i = 4; std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; break;
	}
	while (i < 4)
	{
		if (level == warnings[i] && i >= this->filter)
			{
				std::cout << "[ " << warnings[i] << " ]" << std::endl;
				(this->*message[i])();			
			}
		i++;
	}

}

void Harl::setFilter(int filter)
{
	this->filter = filter;
}