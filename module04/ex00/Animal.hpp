/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:43 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:45:51 by ls               ###   ########.fr       */
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
        virtual ~Animal(void);
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif