/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:33:43 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 13:42:54 by calbor-p         ###   ########.fr       */
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
        WrongAnimal(WrongAnimal const &cl);
        void operator=(WrongAnimal const &cl);       
        virtual ~WrongAnimal(void);
        std::string getType(void) const;
        void makeSound(void) const;
};

#endif