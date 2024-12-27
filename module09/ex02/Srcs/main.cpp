/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/12/06 22:27:18 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/colors.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <list>
#include <sstream>
#include <climits>
#include <vector>
#include "../Includes/PmergeMe.hpp"
#include "../Includes/WrongValueException.hpp"
#include "../Includes/ValueExistException.hpp"

mode debug = NORMAL;

bool isOnlyDigits(char *str)
{
    int i = 0;
    while (str[i])
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '+' )
            return (false);
        i++;
    }
    return (true);
}

bool isUnsignedInt(long long int nb)
{
    if (nb < 0)
        return false;
    if (nb > UINT_MAX)
        return false;
    return true;
}

unsigned int parseStr(char *str)
{
    std::string value(str);
    std::stringstream oss;
    oss << value;
    unsigned long long ui_val;
    oss >> ui_val;

    if (oss.fail() || !isOnlyDigits(str) || !isUnsignedInt(ui_val))
    {
        throw WrongValueException("unsigned int expected");
    }
    return ui_val;
}

bool isValInList(unsigned int val, std::vector<unsigned int> &lst)
{
    std::vector<unsigned int>::iterator it;
    it = lst.begin();
    for (; it != lst.end(); ++it)
    {
        if (*it == val)
            throw ValueExistException("All values must be different");        
    }
    return (false);
}

int main(int ac, char **av)
{
    if (ac < 3)
        std::cout << RED << "Insufficient data, please launch again with numbers"<< RESET << std::endl;
    std::vector<unsigned int> data;
    size_t args = 1;
    if (av[1])
    {
        std::string checkArg(av[1]);
        if (checkArg == "--debug"){
            args++;
            debug = DEBUG;
            std::cout << RED << "=== Running in debug mode ===" << RESET << std::endl;
        }

    }
    for (args; args < ac; ++args)
    {
        try
        {
            unsigned int val = parseStr(av[args]); 
            if (!isValInList(val, data))                
                data.push_back(val);
        }
        catch (WrongValueException &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
            return (1);
        }
        catch (ValueExistException &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
            return (2);
        }
    }
    PmergeMe merge(data);
    merge.printlist();
    merge.sort();
    merge.printlist();
}