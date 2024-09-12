/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ls <ls@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:16:26 by calbor-p          #+#    #+#             */
/*   Updated: 2024/04/11 08:32:29 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
   std::string brainTalk = "HERE IS THE BRAIN";

   std::string *pBrainTalk = &brainTalk;
   std::string &rBrainTalk = brainTalk;

   std::cout << "Addresse de brainTalk : " << pBrainTalk << std::endl;
   std::cout << "Addresse de pBrainTalk : " << &pBrainTalk << std::endl;
   std::cout << "Addresse de rBrainTalk : " << &rBrainTalk << std::endl;

   std::cout << "brainTalk : " << brainTalk << std::endl;
   std::cout << "pBrainTalk : " << *pBrainTalk << std::endl;
   std::cout << "rBrainTalk : " << rBrainTalk << std::endl;
}
