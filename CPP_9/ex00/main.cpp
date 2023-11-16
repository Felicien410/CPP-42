/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:18:30 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/15 16:02:37 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments";
        exit(-1);
    }
    std::map<std::string, float> mapBitcoin;
    BitcoinExchange Exchange;
    
    std::ifstream file("data.csv");
    if (file.is_open()) {
        std::string line;
        float rate;
        while (getline(file, line)) {
            std::string* arr = mySplit(line, ",");
            std::string valueRate = arr[1];
            valueRate.erase(0, valueRate.find_first_not_of(' '));  // Enlever les espaces avant
            valueRate.erase(valueRate.find_last_not_of(' ') + 1);  // Enlever les espaces après
            try {
                rate = std::stof(valueRate);

                // Le reste de votre logique
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erreur de conversion pour la valeur: " << valueRate << std::endl;
                continue; // Passer à la ligne suivante
            }
            Exchange.addCurrency(arr[0], rate);
        }
        file.close();
    
    } else {
            std::cerr << "Unable to open file\n";
    }

    //print map
    for (std::map<std::string, float>::iterator it = mapBitcoin.begin(); it != mapBitcoin.end(); ++it)
         std::cout << it->first << " => " << it->second << '\n';
    
    std::ifstream inputFile(argv[1]);
    if (inputFile.is_open()) {
        std::string line;
        std::getline(inputFile, line);
        float amount;
        while (getline(inputFile, line)) {
            std::string* arr = mySplit(line, "|");
            std::string date = arr[0];
            date.erase(0, date.find_first_not_of(' '));
            
            std::string valueStr = arr[1];
            valueStr.erase(0, valueStr.find_first_not_of(' '));  // Enlever les espaces avant
            valueStr.erase(valueStr.find_last_not_of(' ') + 1);  // Enlever les espaces après

            try {
                amount = std::stof(valueStr);

                // Le reste de votre logique
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erreur de conversion pour la valeur: " << valueStr << std::endl;
                continue; // Passer à la ligne suivante
            }
            if (Exchange.exists(date)) {
                float rate = Exchange.getRate(date);
                float value = amount * rate;
                std::cout << date << " => " << amount << " BTC = " << value << " USD\n";
            } else {
                // Gérer le cas où la date n'est pas trouvée
                std::cout << "Date " << date << " not found. Using closest date...\n";
                // Ici, implémentez la logique pour trouver et utiliser la date la plus proche.
            }
        }
        inputFile.close();
    } else {
    std::cerr << "Unable to open input file\n";
}


}
