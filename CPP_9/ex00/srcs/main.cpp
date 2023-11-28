/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:18:30 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/28 14:11:39 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong number of arguments\n";
        return -1;
    }

    BitcoinExchange exchange;

    loadExchangeRatesFromFile(exchange, "data/data.csv");
    processInputFile(exchange, argv[1]);

    return 0;
}
