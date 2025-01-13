/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2025/01/13 19:46:40 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/colors.hpp"
#include "../Includes/Array.hpp"

template<typename T>
void displayArray(T *arr)
{
    for (size_t i = 0; i < arr->size(); ++i)
    {
        std::cout << (*arr)[i];
        if (i != arr->size() - 1)
           std::cout << " ";
    }
    std::cout << std::endl;
}

    int main()
    {
        std::cout << BOLD_BLUE << "===COPLIEN'S FORM===" << RESET << std::endl;
        Array<int> from(5);
        for (size_t i = 0; i < from.size(); ++i)
        {
            from[i] = i * 3;       
        }
        Array<int> to(from);
        to[2] = 42;
        displayArray(&from);
        displayArray(&to);




        std::cout << BOLD_BLUE << "===INTs ARRAY==="<< RESET << std::endl;
        Array<int> myArray(5);
        for (size_t i = 0; i < myArray.size(); ++i)
        {
            myArray[i] = i * 3;
        }
        displayArray(&myArray);

        try
        {
            std::cout << myArray[8] << std::endl;
        } 
        catch (const OutOfRangeException &e)
        {
            std::cout << std::endl << e.what() << std::endl;
        }

        std::cout << BOLD_BLUE << "===FLOATs ARRAY===" << RESET << std::endl;
        Array<float> myfloatArray(16);
        for (size_t i = 0; i < myfloatArray.size(); ++i)
        {
            myfloatArray[i] = i * 3.02;
        }
        displayArray(&myfloatArray);
        try
        {
            std::cout << myArray[-1] << std::endl;
        } 
        catch (const OutOfRangeException &e)
        {
            std::cout << std::endl << e.what() << std::endl;
        }

        std::cout << BOLD_BLUE << "===STRINGs ARRAY===" << RESET << std::endl;
        Array<std::string> mystringArray(16);
        for (size_t i = 0; i < mystringArray.size(); ++i)
        {
            mystringArray[i] = "miam";
        }
        displayArray(&mystringArray);        
        return 0;
    }
