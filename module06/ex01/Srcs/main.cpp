/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/12/05 20:13:37 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Data.hpp"
#include "../Includes/Serializer.hpp"

int main()
{
    Data *d1 = new Data();
    Data *d1bis;

    Serializer::serialize(d1);
    
    uintptr_t ptr = Serializer::serialize(d1);
    d1bis = Serializer::deserialize(ptr);

    std::cout << ptr << "     "   << d1bis->getId() << std::endl;
    
}
