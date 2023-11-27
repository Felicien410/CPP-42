/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:12:08 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/26 14:15:45 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Harl.hpp"

int main() {
    Harl harl;
    std::string level;

    while (true) {
        std::cout << "Please choose a complain level \n(DEBUG, INFO, WARNING, ERROR) or 'quit' to exit: ";
        std::cin >> level;
        if (level == "quit") {
            break;
        }
        harl.complain(level);
        std::cout << std::endl;
    }
    std::cout << "Goodbye!" << std::endl;
    return 0;
}
