/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:28 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:44:17 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <iostream>

class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(Cat const &cl);
        ~Cat();
        void makeSound(void) const;
        void operator=(Cat const &cl);
};

#endif
