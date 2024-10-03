/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:43 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 13:40:03 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(std::string const &type);    
        Animal(Animal const &cl);
        void operator=(Animal const &cl);
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif