/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:17:31 by calbor-p          #+#    #+#             */
/*   Updated: 2024/04/11 08:15:07 by ls               ###   ########.fr       */
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
  	Zombie();
	Zombie(std::string name);
	~Zombie();
	void set_name(std::string name);
	void announce(void);
	void print_name(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif