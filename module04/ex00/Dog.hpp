/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 15:09:52 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const &cl);
        ~Dog();
        void makeSound(void) const;
        void operator=(Dog const &cl);
};

#endif
