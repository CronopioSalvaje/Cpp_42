/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:28 by ls                #+#    #+#             */
/*   Updated: 2024/08/08 08:49:15 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &cl);
        ~WrongCat();
        void makeSound(void) const;
        void operator=(WrongCat const &cl);
};

#endif
