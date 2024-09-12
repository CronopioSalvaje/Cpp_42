/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AwPhoneBook.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calbor-p <calbor-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:31:04 by calbor-p          #+#    #+#             */
/*   Updated: 2024/09/09 10:31:07 by calbor-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <string>
#include <ctime>

/**
 * ADD : enregistrer un nouveau contact
◦ Si l’utilisateur entre cette commande, le programme lui demande de remplir
une par une les informations du nouveau contact. Une fois tous les champs
complétés, le nouveau contact est ajouté au répertoire.
◦ Un contact possède les champs suivants : first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
peuvent être vides.
• SEARCH : affiche le contact demandé
◦ Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
first name, last name et nickname.
◦ Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
un point (’.’).
◦ Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à af-
ficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
Sinon, affichez les informations du contact, une par ligne
*/

int main (int ac, char **av)
{
    (void)ac;
    (void) av;
    std::string prompt;
    PhoneBook phone_book;

    while(1)
    {
        std::cout << "> ";
        std::cin >> prompt;
        if (prompt == "ADD")
            phone_book.add_contact();
        if (prompt.compare(0,6, "SEARCH",0 ,6) == 0)
            phone_book.display();
        if (prompt == "EXIT")
          break;
    }
    return 0;
}