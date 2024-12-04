/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/09/21 22:18:47 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
    int max = std::numeric_limits<int>::max();
    int min = -std::numeric_limits<int>::max() - 1;
    std::stringstream ss;
    ss << max;
    std::string intMax;
    ss >> intMax;
    ss.clear();
    std::string intMin;
    ss << min;
    ss >> intMin;

    (void) ac;
    if (av[1])
    {
        std::string toConvert(av[1]);
        (void) toConvert;
        ScalarConverter::convert(toConvert);
    }

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("0");
    
    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("33");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("42");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("nan");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("nanf");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("+inf");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("-inf");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("+inff");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("-inff");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert("c");

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert(intMax);

    std::cout << RED << "------------------------" << RESET << std::endl;
    ScalarConverter::convert(intMin);

    std::cout << RED << "------------------------" << RESET << std::endl;
    ss.clear();
    ss << 456.654;
    std::string value;
    ss >> value;
    ScalarConverter::convert(value);
    std::cout << RED << "------------------------" << RESET << std::endl;
    ss.clear();
    value.clear();
    ss << 116.15;
    ss >> value;
    ScalarConverter::convert(value);
    ss.clear();
    value.clear();
    return 0;
}
