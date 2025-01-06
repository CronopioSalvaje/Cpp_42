/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:28:56 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 08:23:08 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bureaucrat.hpp"
#include "../Includes/colors.hpp"


void label(std::string title)
{
    std::cout << BOLD_BLUE << "=== "<< title << " ===" << RESET << std::endl;
}

int main()
{
    label("Creating bureaucrat gontran (22)");
    Bureaucrat gontran("Gontran", 22);
    std::cout << gontran << std::endl;     
    label("Creating bureaucrat toto (155)");
    label("Grade too low test");
    Bureaucrat *toto =  new Bureaucrat("Toto", 155);

    std::cout << *toto << std::endl;    
    toto->demote();
    std::cout << *toto << std::endl;


    label("Promoting tests");
    toto->promote();
    std::cout << *toto << std::endl;
        toto->promote();
    std::cout << *toto << std::endl;
        toto->promote();
    std::cout << *toto << std::endl;
        toto->promote();
    std::cout << *toto << std::endl;
    label("Promoting tests with operator ++");
    for (int i=0; i < 145; i++)
    {
        (*toto)++;
    }
    std::cout << *toto << std::endl;
    label("Grade too high test");
    (*toto)++;
    std::cout << *toto << std::endl;
    label("demoting tests with operator --");
    for (int i=0; i < 145; i++)
    {
        (*toto)--;
    }
    std::cout << *toto << std::endl;

    //cloning toto

   label("Clonning test");
    Bureaucrat toto2(*toto);

    std::cout << toto2 << std::endl;
    
    delete toto;
    return 0;    
}