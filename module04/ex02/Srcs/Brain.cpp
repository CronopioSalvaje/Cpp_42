/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:21:49 by ls                #+#    #+#             */
/*   Updated: 2024/08/09 19:33:20 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Brain.hpp"
#include <cstdlib>

Brain::Brain(): ideas(new std::string[100]), stored(0)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "No Idea !!";
    std::cout << "i'm a new Brain" << std::endl;
}

int Brain::getStored(void) const
{
    return this->stored;
}

Brain::Brain(Brain &br)
{
    //this->ideas = new std::string[100];
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = br.ideas[i];
    this->stored = br.stored;
    std::cout << "i'm a new Brain Clone" << std::endl;    
}

Brain &Brain::operator=(Brain &br)
{
    if (this == &br)
        return *this;
    this->ideas = new std::string[100];
    for (int i = 0; i < 100; i++)
        this->ideas[i] = br.ideas[i];
    this->stored = br.stored;
    return *this;
}


void Brain::newIdea(std::string &idea)
{
    this->ideas[this->stored] = idea;
    this->stored += 1;
    if (this->stored == 100)
        this->stored = 0;
}

std::string Brain::getIdea(void)
{
    int randomIdea;

    randomIdea = 0;
    if (this->stored)
        randomIdea = custom_rand(0, this->stored);
    return this->ideas[randomIdea];
}

Brain::~Brain()
{
    std::cout << "Brain destroyed" << std::endl;
    delete [] this->ideas;
}