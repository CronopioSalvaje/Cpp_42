/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:43:12 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 10:19:54 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Form.hpp"
#include "../Includes/Bureaucrat.hpp"

Form::Form()
{    
}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), isSigned(false)
{
    this->setExecGrade(execGrade);
    this->setSignGrade(signGrade);
}

Form::Form(Form const &cl): _name(cl._name)
{    
    this->isSigned = cl.isSigned;
    this->setExecGrade(execGrade);
    this->setSignGrade(signGrade);    
}

Form::~Form()
{   
}

Form &Form::operator=(Form const &cl)
{
    this->isSigned = cl.isSigned;
    this->setExecGrade(execGrade);
    this->setSignGrade(signGrade);         
    return *this;
}

void Form::sign(void)
{
    this->isSigned = true;
}

void Form::setExecGrade(int grade)
{
    try
    {
        if (grade > 150)
        {
            this->execGrade = 150;
            throw GradeTooLowException();        
        }
        else if(grade < 1)
        {
            this->execGrade = 1;
            throw GradeTooHighException();        
        }
        else
            this->execGrade = grade;
    }
   catch(GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }    
}

void Form::setSignGrade(int grade)
{
    try
    {
        if (grade > 150)
        {
            this->signGrade = 150;
            throw GradeTooLowException();        
        }
        else if(grade < 1)
        {
            this->signGrade = 1;
            throw GradeTooHighException();        
        }
        else
            this->signGrade = grade;
    }
    catch(GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}


const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::string Form::getName(void) const
{
    return this->_name;
}

bool Form::getStatus(void) const
{
    return this->isSigned;
}

int Form::getExecGrade() const
{
    return this->execGrade;
}


int Form::getSignGrade() const
{
    return this->signGrade;
}

void Form::beSigned(Bureaucrat & z)
{
    try
    {
        if (z.getGrade() <= this->getSignGrade())
        {
            this->isSigned = true;
        }
        else
        {
            throw GradeTooLowException();
        }
    }
    catch(GradeTooLowException & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

std::ostream &operator<<(std::ostream &cout, Form const &f)
{
    return cout << f.getName() << " Form "
    << (f.getStatus() == true ? "is signed" : "is not signed") << std::endl
    << "reguired grade to Sign : " << f.getSignGrade() << std::endl
    << "required grade to Execute : " << f.getExecGrade()
    << std::endl;
}