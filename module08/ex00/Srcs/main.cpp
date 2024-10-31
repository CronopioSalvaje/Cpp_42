/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/10/27 18:12:03 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/colors.hpp"
#include "../Includes/easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
    const std::size_t size = 200;
    std::vector<int> even;
    std::deque<int> odd;
    std::list<int> ten;

    for (std::size_t i = 0; i < size; i++)
    {
        int n = static_cast<int>(i);
        if (n % 2 == 0)
            even.push_back(n);
        else
            odd.push_back(n);
        ten.push_back(n*10);
    }
    std::cout << GREEN << "vector : " << RESET << std::endl;
    test_iterator(even, easyfind(even, 100));
    test_iterator(even, easyfind(even, 13));
    
    std::cout << GREEN << "deque : " << RESET << std::endl;
    test_iterator(odd, easyfind(odd, 100));
    test_iterator(odd, easyfind(odd, 13));

    std::cout << GREEN << "list : " << RESET << std::endl;
    test_iterator(ten, easyfind(ten, 100));
    test_iterator(ten, easyfind(ten, -1));
    return 0;
}
