/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:20:35 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/16 12:42:20 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

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
    // std::cout << "date => " << date << std::endl;
    // std::cout << "_currencies.find(date) => " << _currencies.find(date)->first << std::endl;
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

void BitcoinExchange::printMap()
{
    std::map<std::string, double>::iterator it = _currencies.begin();
    while (it != _currencies.end())
    {
        std::cout << "\'" << it->first <<  "\'" << " => " << it->second << std::endl;
        it++;
    }
}

std::string BitcoinExchange::previousDate(const std::string& date)
{
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    int yearInt = std::stoi(year);
    int monthInt = std::stoi(month);
    int dayInt = std::stoi(day);
    if (dayInt == 1)
    {
        if (monthInt == 1)
        {
            yearInt--;
            monthInt = 12;
            dayInt = 31;
        }
        else if (monthInt == 3)
        {
            monthInt--;
            if (isLeapYear(yearInt))
                dayInt = 29;
            else
                dayInt = 28;
        }
        else if (monthInt == 5 || monthInt == 7 || monthInt == 8 || monthInt == 10 || monthInt == 12)
        {
            monthInt--;
            dayInt = 30;
        }
        else
        {
            monthInt--;
            dayInt = 31;
        }
    }
    else
        dayInt--;
    std::string yearStr = std::to_string(yearInt);
    std::string monthStr = std::to_string(monthInt);
    std::string dayStr = std::to_string(dayInt);
    if (monthStr.length() == 1)
        monthStr = "0" + monthStr;
    if (dayStr.length() == 1)
        dayStr = "0" + dayStr;
    return (yearStr + "-" + monthStr + "-" + dayStr);
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}