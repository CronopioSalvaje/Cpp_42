/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2025/01/13 20:13:16 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Base.hpp"
#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"
#include <typeinfo> 
#include <ctime>
#include <cstdlib>
#include <unistd.h>

Base * generate(void)
{

    int nb = rand() % 3 + 1;
    switch(nb)
    {
        case 1:
            return new A;
            break;
        case 2:
            return new B;
            break;
        case 3:
            return new C;
            break;
    }
    return NULL;
}

void identify(Base* p)
{
    A *testA = dynamic_cast<A *>(p);
    B *testB = dynamic_cast<B *>(p);
    C *testC = dynamic_cast<C *>(p);
    if (testA)
        std::cout << "A" ;
    else if (testB)
        std::cout << "B";
    else if (testC)
        std::cout << "C";
    std::cout << std::endl;    
}

void identify(Base& p)
{
    try{
        A testA = dynamic_cast< A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast& e)
    {
        (void) e;
    }
    try{
        B testB = dynamic_cast< B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (const std::bad_cast& e)
    {
        (void) e;
    }
    try{
        C testC = dynamic_cast< C&>(p);
        std::cout << "C" << std::endl;
    }
    catch( const std::bad_cast& e)
    {
        (void) e;
    }
}



int main()
{
    srand(time(NULL));
   Base * ptr = generate();
   Base * ptr2 = generate();
   identify(ptr);
   identify(*ptr2);
   
    
}
