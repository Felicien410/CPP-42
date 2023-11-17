/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:33:49 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/17 16:02:09 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return (-1);
    }
    RNP rnp(argv[1]);
    if (rnp.verifNumbers(argv[1]) == -1)
        return(-1);
    if (rnp.VerifNumberOperand() == -1) 
        return -1;
    rnp.addStack();
        
    return (0);
}