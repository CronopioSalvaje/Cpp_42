/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:43:33 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 12:49:55 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>

class Form
{
    private:
        std::string _name;
        bool isSigned;
        int execGrade;
        int signGrade;
    public:
        Form(void);
        Form(std::string name);
        Form(Form const &cl);
        ~Form();
        void operator=(Form const &cl);
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
#endif
