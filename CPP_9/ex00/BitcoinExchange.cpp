/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:20:35 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/15 15:21:14 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
    if (this != &rhs)
    {
        this->_currencies = rhs._currencies;
    }
    return (*this);
}

void BitcoinExchange::addCurrency(std::string const & name, double rate)
{
    _currencies.insert(std::make_pair(name, rate));
}

bool BitcoinExchange::exists(const std::string& date) const {
    return _currencies.find(date) != _currencies.end();
}

double BitcoinExchange::getRate(const std::string& date)
{
    std::map<std::string, double>::const_iterator it = _currencies.find(date);
    if (it != _currencies.end()) {
        return it->second;
    } else {
        std::cout << "Error: bad input => " << it->second << std::endl;
        return(-1);
    }
}