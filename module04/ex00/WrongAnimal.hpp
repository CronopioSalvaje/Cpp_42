/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:43 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:52:09 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string const &type);        
        virtual ~WrongAnimal(void);
        std::string getType(void) const;
        void makeSound(void) const;
};

#endif