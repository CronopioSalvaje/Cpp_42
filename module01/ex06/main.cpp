/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:21:14 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/16 08:16:49 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

#include <iostream>
#include <string>

int main(int ac,char **args)
{
	Harl harl;
	std::string warnings[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int filter = 0;
	
	if (ac > 2)
	{
		std::cout << "Please call this program with no, or only \033[1,33m ONE \033[0m warning level : "
		<< "DEBUG, INFO, WARNING, ERROR" 
		<< std::endl;
		return (1);
	}	
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