/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:28:56 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 10:23:17 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Form.hpp"
#include "../Includes/Bureaucrat.hpp"

#define line std::cout << std::endl;

int main()
{
    Bureaucrat *toto =  new Bureaucrat("Toto", 5);
    Bureaucrat *president =  new Bureaucrat("M President", 1);
    
    Form outOfBouds("fake", 456, 0);
    Form pres("Presidential grace", 4, 5);
    Form party("Party in the Presidential House", 1, 5);
    
    line;
    std::cout << *toto ;
    toto->signForm(pres);
    std::cout << pres ;
    toto->promote();
    std::cout << *toto ;
    toto->signForm(pres);
    std::cout << pres ;
    line;
    
    
    toto->signForm(party);
    std::cout << party ;  
    line;
    president->signForm(party);
    std::cout << party ;
    president->signForm(party);
    std::cout << party ;
    
    return 0;    
}