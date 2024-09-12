/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:21:14 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/12 22:00:46 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

#include <iostream>
#include <string>

int main(int ac,char **args)
{
	(void )ac;
	Harl harl;
	std::string warnings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int filter = 0;	 
	if (args[1])
	{
		filter = -1;
		for (int i = 0; i < 4; i++)
			if (args[1] == warnings[i])
				filter = i;
	}
	harl.setFilter(filter);
	
	harl.complain("DEBUG");
	harl.complain("VIOLENT");   
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return 0;
}