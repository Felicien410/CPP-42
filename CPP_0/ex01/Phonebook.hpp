/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:58:15 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 16:09:29 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP  // Protection d'inclusion
#define PHONEBOOK_HPP

#include "Contact.hpp"  // Inclure le fichier d'en-tête de la classe Contact
#include <iostream>


class PhoneBook
{
    private:
        Contact m_contacts[8];

    public:
        void initContact(void);
        void displayContact();
        void start(void) const;
        void search();
};

#endif