/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:47 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:03:50 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Brain.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
    private:
        static int count;
    protected:
        std::string _type;
    public:
        int id;
        Animal();
        Animal(std::string const &type);
        Animal(Animal const &cl);
        void operator=(Animal const &cl);  
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif