/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:59 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/29 18:33:42 by feliciencat      ###   ########.fr       */
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
        if (isdigit(args[i]) && args[i + 1] && isdigit(args[i + 1]))
                {
            std::cout << "The numbers always must be less than 10" << std::endl;
            return (-1);
        }    
        if ( (args[i] >= '0' && args[i] <= '9') || args[i] == ' ' || args[i] == '\t' || args[i] == '+' || args[i] == '-' || args[i] == '*' || args[i] == '/' )
        {
        }
        else 
        {
            std::cout << "Error" << std::endl;
            return (-1);
        }
    }  
    return 0;
}

int RNP::VerifNumberOperand()
{
    int operands = 0;
    int numbers = 0;
    for (unsigned int i = 0 ; i < _argv.size() ; i++)
    {
        if (_argv[i] == '+' || _argv[i] == '-' || _argv[i] == '*' || _argv[i] == '/')
            operands++;
        if (isdigit(_argv[i]))
            numbers++;
    }
    if (numbers - 1 != operands)
    {
         std::cout << "Error" << std::endl;
        return(-1);
    }
    return(0);
}


void RNP::addStack()
{
    for (unsigned int i = 0 ; i < _argv.size() ; i++)
    {
        while(_argv[i] == ' ' || _argv[i] == '\t')
            i++;
        if (isdigit(_argv[i]))
        {
            stockage.push(_argv[i] - '0');   
        }
        else if (_argv[i] == '+' || _argv[i] == '-' || _argv[i] == '*' || _argv[i] == '/')
        {
            if (stockage.size() < 2) 
            {
                std::cout << "Error: Not enough numbers for the operation" << std::endl;
                return;
            }
            int b = stockage.top();
            stockage.pop();
            int a = stockage.top();
            stockage.pop();
            if (_argv[i] == '+')
                stockage.push(a + b);
            else if (_argv[i] == '-')
                stockage.push(a - b);
            else if (_argv[i] == '*')
                stockage.push(a * b);
            else if (_argv[i] == '/')
            {
                if (b == 0)
                {
                    std::cout << "Division by 0" << std::endl;
                    return;
                }
                stockage.push(a / b);
            }
        }
        else
        {
            std::cout << "Error: Invalid character" << std::endl;
            return;
        }
    }
    std::cout << stockage.top() << std::endl;
}
