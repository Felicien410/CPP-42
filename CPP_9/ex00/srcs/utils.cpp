/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:38:21 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/28 14:11:56 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

size_t countTokens(const std::string &str, const std::string &sep) {
    size_t count = 0;
    size_t pos = 0;

    while ((pos = str.find(sep, pos)) != std::string::npos) {
        ++count;
        pos += sep.length();
    }

    return count + 1;  // +1 pour le dernier token
}

std::string* mySplit(const std::string &str, const std::string &sep) {
    size_t numTokens = countTokens(str, sep);
    std::string* arr = new std::string[numTokens];

    std::istringstream iss(str);
    std::string token;
    size_t index = 0;

    while (std::getline(iss, token, sep[0])) {
        arr[index++] = token;
    }

    return arr;
}

float verifNumbers(std::string & str)
{
    float amount;
    if (str.length() == 0)
    {
        std::cout << "Error: bad input => " << str << std::endl;
        return -1;
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            std::cout << "Error : not a positive number" << std::endl;
            return -1;
        }
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
        {
            std::cout << "Error: bad input => " << str << std::endl;
            return -1;
        }
    }
    try
    {
            amount = ft_stof(str);
    } 
    catch (const std::invalid_argument& e)
    {
            std::cerr << "Erreur de conversion pour la valeur: " << str << "\n";
            return (-1);
    }
    if (amount < 0 || amount >= 1000)
    {
        std::cout << "Error: too large a number. " << std::endl;
        return -1;
    }
    return amount;
}
void processInputFile(BitcoinExchange& exchange, const std::string& filename) {
    std::ifstream inputFile(filename.c_str());;
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file " << filename << "\n";
        return;
    }

    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value") {
        std::cout << "Error: invalid file format (header)\n" << std::endl;
        return;
    }
    while (getline(inputFile, line)) {
        std::string* arr = mySplit(line, "|");
        std::string date = arr[0];
        date.erase(0, date.find_first_not_of(' '));
        date.erase(date.find_last_not_of(' ') + 1);

        std::string valueStr = arr[1];
        if (valueStr.length() == 0) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        valueStr.erase(0, valueStr.find_first_not_of(' '));
        valueStr.erase(valueStr.find_last_not_of(' ') + 1);
        float amount = verifNumbers(valueStr);
        if (amount == -1)
            continue;
        if (!exchange.exists(date)) {
            std::string closestDate = date;
            while (!exchange.exists(closestDate) && closestDate != "0000-00-00") {
                closestDate = exchange.previousDate(closestDate);
            }
            if (closestDate != "0000-00-00") {
                float rate = exchange.getRate(closestDate);
                float value = amount * rate;
                std::cout << date << " => " << amount << " = " << value << "\n";
            } else {
                std::cout << "No closest date found for " << date << "\n";
            }
        }
        else {
            float rate = exchange.getRate(date);
            float value = amount * rate;
            std::cout << date << " => " << amount << " = " << value << "\n";
        }

    }
    inputFile.close();
}


void loadExchangeRatesFromFile(BitcoinExchange& exchange, const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << "\n";
        return;
    }
    
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate") {
        std::cout << "Error: invalid file format (header)\n" << std::endl;
        return;
    }
    while (getline(file, line)) {
        std::string* arr = mySplit(line, ",");
        std::string valueRate = arr[1];
        valueRate.erase(0, valueRate.find_first_not_of(' '));
        valueRate.erase(valueRate.find_last_not_of(' ') + 1);

        try {
            float rate = ft_stof(valueRate);
            exchange.addCurrency(arr[0], rate);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erreur de conversion pour la valeur: " << valueRate << "\n";
            continue;
        }
    }

    file.close();
}