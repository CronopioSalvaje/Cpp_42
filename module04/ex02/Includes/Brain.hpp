/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:20:29 by ls                #+#    #+#             */
/*   Updated: 2024/08/09 09:15:29 by ls               ###   ########.fr       */
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