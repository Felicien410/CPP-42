/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:49 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/16 16:31:20 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: bad arguments" << std::endl;
        return (-1);
    }
    RNP rnp(argv[1]);
    if (rnp.verifNumbers(argv[1]) == -1)
    {
        return(-1);
    }
    

        
    return (0);
}