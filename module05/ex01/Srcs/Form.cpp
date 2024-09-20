/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:43:12 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 12:52:20 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Form.hpp"

Form::Form()
{    
}

Form::Form(std::string name)
{
}

Form::Form(Form const &cl)
{    

}

Form::~Form()
{
   
}

void Form::operator=(Form const &cl)
{

}


const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}