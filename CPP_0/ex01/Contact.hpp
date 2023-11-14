/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:58:00 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/22 17:26:48 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP  // Protection d'inclusion
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string c_Firstname;
        std::string c_Lastname;
        std::string c_Nickname;
        std::string c_Darkestsecret;
        int c_Index;
        std::string c_Phonenumber;

    public:
        Contact();
        void setFirstName(const std::string &firstname);
        void setLastname(const std::string &lastname);
        void setNickname(const std::string &nickname);
        void setSecret(const std::string &secret);
        void display();
        void setIndex(int index);
        void setNumber(const std::string &number);
        void display_unique();

        
};

#endif  // CONTACT_HPP
