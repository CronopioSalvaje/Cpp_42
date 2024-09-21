/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:28:56 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 11:25:15 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AForm.hpp"
#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Shrubberycreationform.hpp"

#define line std::cout << std::endl;

int main()
{
    //Bureaucrat *toto =  new Bureaucrat("Toto", 5);
    Bureaucrat *president =  new Bureaucrat("M President", 1);
    Shrubberycreationform tree("Chris's garden");
    tree.execute(*president);
    return 0;
}