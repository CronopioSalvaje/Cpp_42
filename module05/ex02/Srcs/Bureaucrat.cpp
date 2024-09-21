/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:50:16 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 16:29:31 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Bureaucrat.hpp"
#include "../Includes/AForm.hpp" 

Bureaucrat::Bureaucrat(): name("Unknown"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    try
    {
        this->setGrade(grade);        
    }
    catch (GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;        
    }
    catch (GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;        
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &toClone): name(toClone.name)
{
        this->grade = toClone.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &toClone)
{
  //  this->name = toClone.name;
    if (this != &toClone)
        this->grade = toClone.grade;
    return *this;
}

Bureaucrat &Bureaucrat::operator++(void)
{
    this->promote();
    return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
    this->promote();
    return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
    this->demote();
    return *this;
}

Bureaucrat &Bureaucrat::operator--(void)
{
    this->demote();
    return *this;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
    {
        this->grade = 1;
        throw GradeTooHighException();
    }
    if (grade > 150)
    {
        this->grade = 150;
        throw GradeTooLowException();
    }
    else
        this->grade = grade;
}

std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too Low!";
}

void Bureaucrat::promote(){
    try
    {
        this->setGrade(grade - 1);        
    }
    catch (GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;        
    }
    catch (GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;        
    }

}

void Bureaucrat::demote(){
  try
    {
        this->setGrade(grade + 1);        
    }
    catch (GradeTooHighException & e)
    {
        std::cout << e.what() << std::endl;        
    }
    catch (GradeTooLowException & e)
    {
        std::cout << e.what() << std::endl;        
    }
}

void Bureaucrat::signForm(AForm &form)
{
    if (form.getStatus()){
        std::cout << this->name << " couldn’t sign " << form.getName() << " because it was already signed" << std::endl;
        return;
    }
    
    if (!form.getStatus())
        form.beSigned(*this);

    if (form.getStatus())
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->name << " couldn’t sign " << form.getName() << " because his grade is too low" << std::endl;
}

std::ostream &operator<<(std::ostream &cout, Bureaucrat const &dusty)
{
    return cout << dusty.getName() << ", bureaucrat grade " <<  dusty.getGrade() << std::endl;
}


Bureaucrat::~Bureaucrat()
{
}