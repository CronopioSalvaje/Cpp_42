/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:43:33 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/21 12:00:53 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <exception>
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        std::string target;
        bool isSigned;
        int execGrade;
        int signGrade;
    public:
        AForm(void);
        AForm(std::string name, int signGrade, int execGrade);
        AForm(AForm const &cl);
        void sign(void);
        void execute(Bureaucrat const & executor) const;
        virtual void action();
        bool getStatus(void) const;
        void beSigned(Bureaucrat & z);
        void setExecGrade(int grade);
        void setSignGrade(int grade);
        int getExecGrade(void) const;
        int getSignGrade(void) const;
        std::string getTarget(void) const;
        void setTarget(std::string target);
        std::string getName(void) const;
        ~AForm();
        AForm &operator=(AForm const &cl);
        class GradeTooHighException : public std::exception
        {
            public : 
                const char* what() const throw();
        };
         class GradeTooLowException : public std::exception
        {
            public : 
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &cout, AForm const &form);

#endif
