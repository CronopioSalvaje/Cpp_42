/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:31:13 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/09 10:31:15 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    this->time = (long long int) std::time(NULL);
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName,
    std::string phoneNumber, std::string darkSecret){
    Contact();
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkSecret;   
}

long long int Contact::get_timestamp(void)
{
    return this->time;
}

void Contact::set_field(std::string value, Entry field)
{
    switch(field){
        case FIRSTNAME : this->firstName = value; break;
        case LASTNAME : this->lastName = value; break;
        case NICKNAME : this->nickName = value; break;
        case PHONENUMBER : this->phoneNumber = value; break;
        case DARKSECRET: this->darkestSecret = value; break;
    }
}

std::string Contact::get_field(Entry field)
{
    switch(field){
        case FIRSTNAME : return this->firstName; break;
        case LASTNAME : return this->lastName; break;
        case NICKNAME : return this->nickName; break;
        case PHONENUMBER : return this->phoneNumber; break;
        case DARKSECRET: return this->darkestSecret; break;
    }
    return NULL;
}

void Contact::displayContact(void)
{
    std::cout << "First Name : " << this->firstName << std::endl;
    std::cout << "Last Name : " << this->lastName << std::endl;
    std::cout << "Nickname : "<< this->nickName << std::endl;
    std::cout << "Phone Number : " << this->phoneNumber << std::endl;
    std::cout << "Dark Secret : " << this->darkestSecret << std::endl;
}
