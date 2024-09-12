/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:17:31 by calbor-p          #+#    #+#             */
/*   Updated: 2024/04/10 09:29:23 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string name;

  public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void print_name(void);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif