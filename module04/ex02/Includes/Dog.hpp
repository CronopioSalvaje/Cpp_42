/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:07 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:03:10 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>

class Dog :public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(Dog const &cl);
        ~Dog();
        void setIdea(std::string &idea);
        Brain *getBrain();
        std::string getIdea(void);
        void makeSound(void) const;
        void operator=(Dog const &cl);
};

#endif
