/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:48:55 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/20 08:35:27 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        Bureaucrat &operator=(Bureaucrat const &toClone);
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &toClone);        
        Bureaucrat &operator++(void);
        Bureaucrat operator++(int);
        Bureaucrat &operator--(void);
        Bureaucrat operator--(int);
        int getGrade(void) const;
        std::string getName(void) const;
        void setGrade(int grade);
        void promote(void);
        void demote(void);
        class GradeTooHighException : std::exception
        {
            public : 
                const char* what() const throw();
        };
        class GradeTooLowException : std::exception
        {
            public : 
                const char* what() const throw();
        };
        ~Bureaucrat();

        
        
};

std::ostream &operator<<(std::ostream &cout, Bureaucrat const &dusty);


#endif