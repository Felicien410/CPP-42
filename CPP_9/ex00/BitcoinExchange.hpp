/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:18:55 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/15 15:16:49 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include<map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    public :
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange();
        BitcoinExchange & operator=(BitcoinExchange const & rhs);

        void addCurrency(std::string const & name, double rate);
        bool exists(const std::string& date) const;
        double getRate(const std::string& date);
        void printCurrencies();
        void printCurrency(std::string const & name);
        void printAllCurrencies();
    private:
        std::map<std::string, double> _currencies;
        
};

#endif
