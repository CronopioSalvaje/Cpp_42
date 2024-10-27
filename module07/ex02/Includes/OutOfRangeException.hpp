/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutOfRangeException.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:00:54 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 21:15:23 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTOFRANGEEXCEPTION_HPP
#define OUTOFRANGEEXCEPTION_HPP

#include <string>
#include <exception>

class OutOfRangeException : public std::exception
{
    private : 
        std::string message;
    public :    
        explicit OutOfRangeException(std::string message);
        const char *what() const throw();
        ~OutOfRangeException() throw();
};


#endif