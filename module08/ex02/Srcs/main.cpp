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
#include "../Includes/MutantStack.tpp"

void testIterators(MutantStack<int> &mstack)
{
    std::cout << "===Test Iterators===" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " - ";
        ++it;
    }
    std::cout << std::endl;
}

void testList()
{
    std::cout << "===Test List===" << std::endl;
    std::list<int> lst;
    lst.push_front(5);
    lst.push_front(17);
    std::cout << "front : " << lst.front() << std::endl;    
    std::cout << "size : " << lst.size() << std::endl;
    lst.pop_front();
    std::cout << "front : " << lst.front() << std::endl;    
    std::cout << "size : " << lst.size() << std::endl;
    lst.push_front(3);
    lst.push_front(5);
    lst.push_front(737);
    //[...]
    lst.push_front(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

}

void testConstIterators(MutantStack<int> const &mstack)
{
    std::cout << "===Test Const Iterators===" << std::endl;
    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " - ";
        ++it;
    }
    std::cout << std::endl;
}

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top : " << mstack.top() << std::endl;
    std::cout << "size : " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "top : " << mstack.top() << std::endl;
    std::cout << "size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    testIterators(mstack);
    testConstIterators(mstack);
    std::stack<int> s(mstack);
    testList();
    return 0;    
}