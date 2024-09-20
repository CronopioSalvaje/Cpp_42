/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:28:56 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 12:42:45 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"

int main()
{
    Bureaucrat *toto =  new Bureaucrat("Toto", 155);
    std::cout << *toto << std::endl;
    
    toto->demote();
    std::cout << *toto << std::endl;
    toto->promote();
    std::cout << *toto << std::endl;
        toto->promote();
    std::cout << *toto << std::endl;
        toto->promote();
    std::cout << *toto << std::endl;
        toto->promote();
    std::cout << *toto << std::endl;
    //promoting toto :
    for (int i=0; i < 145; i++)
    {
        (*toto)++;
    }
    std::cout << *toto << std::endl;
    (*toto)++;
    std::cout << *toto << std::endl;
    // demoting toto : 
    for (int i=0; i < 145; i++)
    {
        (*toto)--;
    }
    std::cout << *toto << std::endl;

    //cloning toto

    Bureaucrat toto2(*toto);

    std::cout << toto2 << std::endl;
    
    Bureaucrat gontran("Gontran", 22);
    std::cout << gontran << std::endl; 
    
    
    delete toto;
    return 0;    
}