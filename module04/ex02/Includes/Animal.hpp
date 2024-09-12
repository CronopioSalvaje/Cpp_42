/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:43 by ls                #+#    #+#             */
/*   Updated: 2024/08/10 08:48:45 by ls               ###   ########.fr       */
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
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};

#endif