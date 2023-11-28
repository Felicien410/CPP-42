/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:18:55 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/28 12:37:20 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
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
        void printMap();
        std::string previousDate(const std::string& date);
        bool isLeapYear(int year);
        static int ft_stoi(const std::string& str);
        static float ft_stof(const std::string& str);
        void printCurrencies();
        void printCurrency(std::string const & name);
        void printAllCurrencies();
    private:
        std::map<std::string, double> _currencies;
        
};

size_t countTokens(const std::string &str, const std::string &sep);
std::string* mySplit(const std::string &str, const std::string &sep);
void loadExchangeRatesFromFile(BitcoinExchange& exchange, const std::string& filename);

#endif

