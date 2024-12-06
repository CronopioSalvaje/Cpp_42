/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:38 by ls                #+#    #+#             */
/*   Updated: 2024/12/06 17:47:03 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Base.hpp"
#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"
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
    p.identify();
}

int main()
{
    srand(time(NULL));
   Base * ptr = generate();
   Base * ptr2 = generate();
   identify(ptr);
   identify(*ptr2);
   
    
}
