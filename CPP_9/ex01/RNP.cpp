/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:59 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/16 16:35:30 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

RNP::RNP(std::string argv)
{
    _argv = argv;
}

RNP::RNP(RNP const & src)
{
    *this = src;
    return ;
}

RNP::~RNP()
{
}

RNP & RNP::operator=(RNP const & rhs)
{
    if (this != &rhs)
    {
        this->stockage = rhs.stockage;
    }
    return (*this);
}

int RNP::verifNumbers(std::string args)
{
    for (unsigned int i = 0; i < args.size() ; i++)
    {
        if ( (args[i] >= '0' && args[i] <= '9') || args[i] == ' ' || args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/' )
        {
        }
        else 
        {
            std::cout << "Error: bad arguments" << std::endl;
            return (-1);
        }
    }  
    return 0;
}

void RNP::addStack()
{
    for (unsigned int i = 0 ; i < _argv.size() ; i++)
    {
        
    }
}
