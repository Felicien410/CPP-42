/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:57:52 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/01 19:07:49 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact()
{
};

void Contact::setFirstName(const std::string &firstname)
{
    c_Firstname = firstname;
}

void Contact::setLastname(const std::string &lastname)
{ 
    c_Lastname= lastname;
}

void Contact::setNickname(const std::string &nickname)
{ 
    c_Nickname= nickname;
}

void Contact::setSecret(const std::string &secret)
{ 
    c_Darkestsecret = secret;
}

void Contact::setIndex(int index)
{ 
    c_Index = index;
}

void Contact::setNumber(const std::string &number)
{ 
    c_Phonenumber = number;
}

void Contact::display()
{
    if(c_Firstname.empty() || c_Lastname.empty() || c_Nickname.empty())
        return;

    std::cout << "|" << formatColumn(std::to_string(c_Index))
              << "|" << formatColumn(c_Firstname)
              << "|" << formatColumn(c_Lastname)
              << "|" << formatColumn(c_Nickname)
              << "|" << std::endl;
}

void Contact::display_unique()
{
    if(c_Firstname.empty() || c_Lastname.empty() || c_Nickname.empty())
    {
        std::cout << "This index does not exist, create it before\n";
        return;
    }

std::cout << "Index: " << formatColumn(std::to_string(c_Index)) << std::endl
          << "Firstname: " << formatColumn(c_Firstname) << std::endl
          << "Lastname: " << formatColumn(c_Lastname) << std::endl
          << "Nickname: " << formatColumn(c_Nickname) << std::endl
          << "Darkestsecret: " << formatColumn(c_Darkestsecret) << std::endl
          << "Phonenumber: " << formatColumn(c_Phonenumber) << std::endl;
}
