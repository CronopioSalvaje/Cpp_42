/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:31:44 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/09 10:32:00 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
 PhoneBook
◦ Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite.
*/

class PhoneBook
{
  private:
	int entries;
	Contact contacts[8];

  public:
	PhoneBook();
	void add_contact();
    int find_oldest(void);
	void promptField(std::string field_name, std::string &field_value);
    std::string get_max_length(std::string value);
	int display(void);    
};