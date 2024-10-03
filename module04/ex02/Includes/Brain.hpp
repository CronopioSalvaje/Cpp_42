/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:03:33 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/03 14:03:37 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include "poly.hpp"
#include <iostream>
#include <string>

class Brain
{
private:
    std::string *ideas;
    int stored;
public:
    Brain();
    Brain(Brain &br);
    void newIdea(std::string &idea);
    int getStored() const;
    std::string getIdea(void);
    Brain &operator=(Brain &br);
    virtual ~Brain();
};


#endif