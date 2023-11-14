/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:30 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 09:34:31 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string getStringInput(const std::string &prompt)
{
    std::string value;

    std::cout << "\033[34m" << prompt << "\033[0m";
    std::getline(std::cin, value);
    while (value.empty())
    {
            std::cout << "\033[31m" << "Please enter valid value!" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << prompt << "\033[0m";
            std::getline(std::cin, value);
    }
    return value;
}

std::string formatColumn(const std::string &input)
{
    if (input.size() <= 10)
        return std::string(10 - input.size(), ' ') + input;
    else
        return input.substr(0, 9) + ".";
}