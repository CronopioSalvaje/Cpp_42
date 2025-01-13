/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/10/27 18:48:26 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/colors.hpp"
#include "../Includes/iter.hpp"

int main()
{
    int intArray[] = {0,1,2,3,4,5,6,7,8,9};
    float floatArray[] = {1.2,2.5,5.2,7.9};
    std::string strArray[] = {"Yes", "No", "Don't Know"};
    std::cout << BOLD_BLUE << "===INT ARRAY===" << RESET << std::endl;
    ::iter(intArray, 10, display);
    ::iter(intArray, 10, add2);
    std::cout << std::endl;
    ::iter(intArray, 10, display);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << BOLD_BLUE << "===FLOAT ARRAY===" << RESET << std::endl;
    ::iter(floatArray, 4, display);
    ::iter(floatArray, 4, add2);
    std::cout << std::endl;
    ::iter(floatArray, 4, display);
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << BOLD_BLUE << "===STRING===" << RESET << std::endl;
    ::iter(strArray, 3, display);
    ::iter(strArray, 3, add2);
    std::cout << std::endl;
    ::iter(strArray, 3, display);
    std::cout << std::endl;
    std::cout << std::endl;
    
    return 0;
}
