/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:38:21 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/16 13:28:01 by feliciencat      ###   ########.fr       */
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

void loadExchangeRatesFromFile(BitcoinExchange& exchange, const std::string& filename) {
    std::ifstream file(filename);
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
            float rate = std::stof(valueRate);
            exchange.addCurrency(arr[0], rate);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erreur de conversion pour la valeur: " << valueRate << "\n";
            continue;
        }
    }

    file.close();
}