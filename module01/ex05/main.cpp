/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:21:14 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/12 16:59:19 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Harl.hpp"

#include <iostream>
#include <string>

int main(int ac,char **av)
{
	(void )ac;
	(void)av;
	Harl harl;
	harl.complain("DEBUG");   
	harl.complain("VIOLENT");   
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return 0;
}