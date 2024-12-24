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
#include "../Includes/Span.hpp"
#include <ctime>
#include <cstdlib>

bool debugMode = false;

template<typename T>
void swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

int getRandInRange(int min, int max)
{   
    if (min > max)
        swap(&min, &max);
    unsigned long long range = static_cast<unsigned long long>(max) - static_cast<unsigned long long>(min) + 1;
    if (range > INT_MAX)
        range = INT_MAX;
    return (min + rand() % (range));
}

void fillSpan(Span &span, unsigned int times, int min, int max)
{
    std::vector<int> v;
    while (times--)
    {
        int r = getRandInRange(min, max);
        v.push_back(r);
    }
    span.addRange(v.begin(), v.end());
}



void quickTest()
{
    std::cout <<  BLUE << "custom quick test in range -15 - 100\n\n"  << RESET;
    Span sp = Span(15);
    sp.addNumber(-15);
    sp.addNumber(10);
    sp.addNumber(15);
    sp.addNumber(20);
    sp.addNumber(25);
    sp.addNumber(30);
    sp.addNumber(35);
    sp.addNumber(40);
    sp.addNumber(45);
    sp.addNumber(50);
    sp.addNumber(55);
    sp.addNumber(60);
    sp.addNumber(65);
    sp.addNumber(70);
    sp.addNumber(100);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout <<  BLUE << "end test ****************************\n\n"  << RESET;
}

void fillSpanTest(int it, int min, int max)
{
    std::cout << BLUE << "Testing with interval "<< min << " - " << max << RESET << std::endl;

    Span sp = Span(it);
    fillSpan(sp, it, min, max);
    sp.setDebug(debugMode);
    sp.debugSpan();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout <<  BLUE << "end test ****************************\n\n"  << RESET;
}

void failSpanTest(int it, int min, int max)
{
    std::cout << BLUE << "Testing with interval "<< min << " - " << max << RESET << std::endl;

    Span sp = Span(it - 2);
    fillSpan(sp, it, min, max);
    sp.setDebug(debugMode);
    sp.debugSpan();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout <<  BLUE << "end test ****************************\n\n"  << RESET;
}


void failSpanTestInsuficientData(bool O)
{

    Span sp = Span(1);
    if (O)
        sp.addNumber(1);
    std::cout << BLUE << "Insuficient data ("<< sp.getSize() << "element)" << std::endl;
    sp.setDebug(debugMode);
    sp.debugSpan();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout <<  BLUE << "end test ****************************\n\n"  << RESET;
}

void mandatoryTest()
{
    std::cout << BLUE << "Subjet main test" <<  RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout <<  BLUE << "end test ****************************\n\n"  << RESET;
}

int main(int ac, char **av)
{
    std::string eval;
    srand(time(NULL));
    if (ac == 2)
    {
        eval = av[1];
        if (eval == "--debug")
            debugMode = true;        
    }
    if (debugMode)
    {
        std::cerr << RED << "debug mode activated..." << std::endl;    
    }
    mandatoryTest();
    quickTest();
    failSpanTest(15,- 100, 100);
    failSpanTestInsuficientData(false);
    failSpanTestInsuficientData(true);
    fillSpanTest(2, 0, 30);
    fillSpanTest(10000,INT_MIN, INT_MAX);
    fillSpanTest(100000,-123123,123123);
    std::cerr << RESET;
    return 0;
}
