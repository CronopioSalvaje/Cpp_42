/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:31:36 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/09 10:31:39 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    entries = 0;
}

int PhoneBook::find_oldest(void)
{
    int i;
    int index;

    i = 0, index = 0;
    long long int saved_tt = (long long int)std::time(NULL);
    while(i < 8)
    {
        if (contacts[i].get_timestamp() < saved_tt)
        {
            saved_tt = contacts[i].get_timestamp();
            index = i;
        }
        i++;
    }
    return index;
}

void PhoneBook::promptField(std::string field_name, std::string &field_value)
{   
    while(field_value.length() == 0)
    {
        std::cout << field_name << " : ";
        std::getline(std::cin,field_value);
    }
    //std::cout << std::endl;
}


void PhoneBook::add_contact(void)
{
 /*   first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret).*/
    int index;

    index = 0;

    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string darkSecret;
    std::string nickName;
   // long long int time;
    std::cin.ignore(1000, '\n') ;
    this->promptField("First Name", firstName);
    this->promptField("Last Name", lastName);
    this->promptField("Nickname", nickName);
    this->promptField("Phone Number", phoneNumber);
    this->promptField("Dark Secret", darkSecret); 

    Contact contact;

    contact.set_field(firstName, FIRSTNAME);
    contact.set_field(lastName, LASTNAME);
    contact.set_field(phoneNumber, PHONENUMBER);
    contact.set_field(darkSecret, DARKSECRET);
    contact.set_field(nickName, NICKNAME);
    

    if (this->entries < 8)
        index = this->entries;
    else
        index = this->find_oldest();
    this->contacts[index] = contact;

    if (this->entries < 8)
        this->entries++;
/*
    std::cout << contacts[index].get_field(FIRSTNAME) << " " << contacts[index].get_field(LASTNAME) << std::endl;
    std::cout << contacts[index].get_field(NICKNAME) << std::endl;
    std::cout << contacts[index].get_field(PHONENUMBER) << std::endl;
    std::cout << contacts[index].get_field(DARKSECRET) << std::endl;*/

}

std::string PhoneBook::get_max_length(std::string value)
{
    if (value.length() > 9)
        return (value.substr(0,9) + ".");
    return value;
}

int PhoneBook::display(void)
{
    int i;
    int index;

    index = -1;
    i = 0;
    std::cout << std::right << std::setw(10) << "Index" << '|';
    std::cout << std::right << std::setw(10) << "First Name" << '|';
    std::cout << std::right << std::setw(10) << "Last Name" << '|';
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
    while (i < this->entries)
    {
        std::cout << std::right << std::setw(10) << i + 1 << '|';
        std::cout << std::right << std::setw(10) << this->get_max_length(this->contacts[i].get_field(FIRSTNAME)) << '|';
        std::cout << std::right << std::setw(10) << this->get_max_length(this->contacts[i].get_field(LASTNAME)) << '|';
        std::cout << std::right << std::setw(10) << this->get_max_length(this->contacts[i].get_field(NICKNAME)) << std::endl;
        i++;
    }
    if (this->entries == 0)
        return 0;
    while (index < 1 || index > this->entries)
    {
        std::cout << "Index ? > "; 
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cout << "Invalid index ! Please chose a valid index (1-8)" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
        }
    }

    contacts[index - 1].displayContact();
    return index - 1;

}