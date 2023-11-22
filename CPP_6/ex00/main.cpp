/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:46:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 11:16:18 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    ScalarConverter scalarConverter(argv[1]);
    scalarConverter.convert();
    return (0);
}
