/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OutOfRangeException.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:00:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/10/27 21:10:38 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/OutOfRangeException.hpp"


OutOfRangeException::OutOfRangeException(std::string message) : message(message)
{    
}

const char *OutOfRangeException::what() const throw()
{
    return message.c_str();
}

OutOfRangeException::~OutOfRangeException() throw() {};