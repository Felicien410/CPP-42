/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:58:04 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/22 17:18:45 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Phonebook.hpp"
#include "Contact.hpp" 

int main(void)
{
    PhoneBook book;
    std::string readline = "";
    book.start();
    while(readline.compare("EXIT") != 0)
    {
        if (!readline.compare("ADD"))
        {
            book.initContact();
        }
        else if (!readline.compare("SEARCH"))
        {
            book.displayContact();
            book.search();
        }
    std::cout << "> " << std::flush;
    std::getline(std::cin, readline);
    }
    return(1);
}