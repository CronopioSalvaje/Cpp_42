/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:30:31 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/09 10:30:33 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < ac)
	{
		while (av[i][j])
		{
			char c = toupper(av[i][j]);
			std::cout << c;
			j++;
		}
		j = 0;
	}

	std::cout << std::endl;
	return (0);
}