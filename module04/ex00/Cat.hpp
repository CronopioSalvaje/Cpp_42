/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:28 by ls                #+#    #+#             */
/*   Updated: 2024/10/03 15:09:46 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const &cl);
        ~Cat();
        void makeSound(void) const;
        void operator=(Cat const &cl);
};

#endif
