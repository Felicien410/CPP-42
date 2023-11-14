/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:58:10 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/29 08:00:26 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"


void PhoneBook::initContact(void)
{
    static int i;
    m_contacts[i % 8].setFirstName(getStringInput("please enter Firstname\n"));
    m_contacts[i % 8].setLastname(getStringInput("please enter Lastname\n"));
    m_contacts[i % 8].setNickname(getStringInput("please enter Nickename\n"));
    m_contacts[i % 8].setSecret(getStringInput("please enter Darkest secret\n"));
    m_contacts[i % 8].setNumber(getStringInput("please enter the Phone number\n"));
    m_contacts[i % 8].setIndex(i % 8);
    i++;
}

void PhoneBook::displayContact()
{
    std::cout << "~~ HERE ARE THE INFORMATIONS OF YOUR CONTACTS ~~" << std::endl;
    std::cout << "|" << formatColumn("Index")
              << "|" << formatColumn("First Name")
              << "|" << formatColumn("Last Name")
              << "|" << formatColumn("Nick Name")
              << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

    for(size_t i = 0; i <= 8; i++)
    {
        m_contacts[i].display();
    }
    std::cout << std::endl;
}

void PhoneBook::search()
{
    int     input = -1;
    bool    valid = false;

    while (!valid)
    {
        std::cout << "🔍 Please enter the index of the contact you'd like to view: ";
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8))
        {
            valid = true;
            this->m_contacts[input].display_unique();
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            return;
        } 
        else
        {
            std::cout << "Invalid index retry plz" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
}

void    PhoneBook::start(void) const
{
        std::cout << "📞 Hey there! What would you like to do today? 😊" << std::endl;
        std::cout << "   ✨ ADD - Add a new contact" << std::endl;
        std::cout << "   🕵️ SEARCH - Look up a contact" << std::endl;
        std::cout << "   🚪 EXIT - Say goodbye and close the phonebook" << std::endl;
}
