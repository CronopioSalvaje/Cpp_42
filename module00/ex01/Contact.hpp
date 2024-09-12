/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:31:22 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/09 10:31:23 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

typedef enum s_entry{
    FIRSTNAME,
    LASTNAME,
    NICKNAME,
    PHONENUMBER,
    DARKSECRET    
} Entry;

class Contact
{
    private:
           std::string firstName;
           std::string lastName;
           std::string phoneNumber;
           std::string nickName;
           std::string darkestSecret;
           long long int time;

    public:
        Contact();
        Contact(std::string firstName, std::string lastName, std::string nickName,
        std::string phoneNumber, std::string darkSecret);
        void displayContact(void);
        void set_field(std::string value, Entry field);
        std::string get_field(Entry field);

        long long int get_timestamp(void);
};

#endif

/*
 PhoneBook
◦ Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.*/