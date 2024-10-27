/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/10/27 21:26:41 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN "\033[32m"
#define DEFAULT_COLOR "\033[0m"

#include "../Includes/Array.hpp"

int main()
{
    Array<int> myArray(5);
    for (size_t i = 0; i < myArray.size(); ++i)
    {
        myArray[i] = i * 3;
        std::cout << myArray[i] << " ";
    }

    try
    {
        std::cout << myArray[8] << std::endl;
    } 
    catch (const OutOfRangeException &e)
    {
         std::cout << std::endl << e.what() << std::endl;
    }

    Array<float> myfloatArray(16);
    for (size_t i = 0; i < myfloatArray.size(); ++i)
    {
        myfloatArray[i] = i * 3.02;
        std::cout << myfloatArray[i] << " ";
    }


    try
    {
        std::cout << myArray[-1] << std::endl;
    } 
    catch (const OutOfRangeException &e)
    {
         std::cout << std::endl << e.what() << std::endl;
    }

    Array<std::string> mystringArray(16);
    for (size_t i = 0; i < mystringArray.size(); ++i)
    {
        mystringArray[i] = "miam";
        std::cout << mystringArray[i] << " ";
    }
    
    return 0;
}
