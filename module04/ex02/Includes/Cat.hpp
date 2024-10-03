/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:23 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:03:24 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(Cat const &cl);
        ~Cat();
        void setIdea(std::string &idea);
        Brain *getBrain();
        std::string getIdea(void);
        void makeSound(void) const;
        void operator=(Cat const &cl);
};

#endif
