/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/08/10 07:58:01 by ls               ###   ########.fr       */
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
