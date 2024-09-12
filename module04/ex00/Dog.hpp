/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:44:24 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>

class Dog : virtual public Animal
{
    public:
        Dog();
        Dog(Dog const &cl);
        ~Dog();
        void makeSound(void) const;
        void operator=(Dog const &cl);
};

#endif
