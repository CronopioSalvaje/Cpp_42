/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:43:33 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 23:44:03 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private:
        std::string _name;
        bool isSigned;
        int execGrade;
        int signGrade;
    public:
        Form(void);
        Form(std::string name, int signGrade, int execGrade);
        Form(Form const &cl);
        void sign(void);
        bool getStatus(void);
        void beSigned(Bureaucrat const & z);
        void setExecGrade(int grade);
        void setSignGrade(int grade);
        int getExecGrade();
        int getSignGrade();
        std::string getName(void);
        ~Form();
        Form &operator=(Form const &cl);
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

std::ostream &operator<<(std::ostream &cout, Form const &form);
#endif
