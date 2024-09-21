/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:40:17 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 16:24:29 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/AForm.hpp"
#include "../Includes/Bureaucrat.hpp"

AForm::AForm()
{    
}

AForm::AForm(std::string name): _name(name), isSigned(false), execGrade(150), signGrade(150)
{
    
}

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), isSigned(false)
{
    this->setExecGrade(execGrade);
    this->setSignGrade(signGrade);
}

AForm::AForm(AForm const &cl): _name(cl._name)
{    
    this->isSigned = cl.isSigned;
    this->setExecGrade(execGrade);
    this->setSignGrade(signGrade);    
}

AForm::~AForm()
{   
}

AForm &AForm::operator=(AForm const &cl)
{
    this->isSigned = cl.isSigned;
    this->setExecGrade(execGrade);
    this->setSignGrade(signGrade);         
    return *this;
}

void AForm::sign(void)
{
    this->isSigned = true;
}

void AForm::setExecGrade(int grade)
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

void AForm::setSignGrade(int grade)
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


const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::string AForm::getName(void) const
{
    return this->_name;
}

bool AForm::getStatus(void) const
{
    return this->isSigned;
}

int AForm::getExecGrade() const
{
    return this->execGrade;
}


int AForm::getSignGrade() const
{
    return this->signGrade;
}

void AForm::beSigned(Bureaucrat & z)
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



void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
    {
        std::cout << this->getName() << " is not signed !!" << std::endl; 
        return ;
    }
    try
    {
        if (executor.getGrade() <= this->getExecGrade() && this->isSigned)
        {
            this->action();
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


std::string AForm::getTarget(void) const
{
    return this->target;
}

void    AForm::setTarget(std::string target)
{
    this->target = target;
}

std::ostream &operator<<(std::ostream &cout, AForm const &f)
{
    return cout << f.getName() << " Form "
    << (f.getStatus() == true ? "is signed" : "is not signed") << std::endl
    << "reguired grade to Sign : " << f.getSignGrade() << std::endl
    << "required grade to Execute : " << f.getExecGrade()
    << std::endl;
}