/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:11:05 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/13 12:41:34 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data *data = new Data;
    Serialization reinterepret;

    data->s1 = "Felicien";
    data->n = 20;
    data->s2 = "Catteau";

    std::cout << "Address: " << reinterepret.serialize( data ) << std::endl;
    
    std::cout << "Name: " << reinterepret.deserialize( reinterepret.serialize( data ) )->s1 << std::endl;
    std::cout << "Age: " << reinterepret.deserialize( reinterepret.serialize( data ) )->n << std::endl;
    std::cout << "Name: " << reinterepret.deserialize( reinterepret.serialize( data ) )->s2 << std::endl;

    delete data;

    return EXIT_SUCCESS;
}