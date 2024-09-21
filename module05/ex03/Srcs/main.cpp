/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:28:56 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 17:29:46 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AForm.hpp"
#include "../Includes/Bureaucrat.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"

#define line std::cout << std::endl;

int main()
{
    //Bureaucrat *toto =  new Bureaucrat("Toto", 5);
    Bureaucrat *president =  new Bureaucrat("Zaphod Beeblebrox, President of the Galaxy", 1);
    ShrubberyCreationForm tree("Chris's garden");
    president->signForm(tree);
    tree.execute(*president);

    ShrubberyCreationForm strange("old garden");
    Bureaucrat *plouc =  new Bureaucrat("M Plouc", 150);
    plouc->signForm(strange);
    strange.execute(*plouc);
    
    RobotomyRequestForm meee("Christophe");
    president->signForm(meee);
    meee.execute(*president);

    PresidentialPardonForm pardon("Christophe");
    president->signForm(pardon);
    pardon.execute(*president);
    
    

    

    
    

    

    
    return 0;
}