/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:28:24 by calbor-p          #+#    #+#             */
/*   Updated: 2024/12/05 21:28:27 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Base.hpp"
#include <iostream>

class A : public Base
{
    private:
        std::string _name;
    public:
        A(void);
        ~A();
};


