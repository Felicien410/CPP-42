/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:11:05 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/23 09:17:01 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main() {
    Data *data = new Data;
    data->s1 = "Felicien";
    data->n = 20;
    data->s2 = "Catteau";

    unsigned long rawPtr = Serialization::serialize(data);

    std::cout << "Address: " << rawPtr << std::endl;
    std::cout << "Name: " << Serialization::deserialize(rawPtr)->s1 << std::endl;
    std::cout << "Age: " << Serialization::deserialize(rawPtr)->n << std::endl;
    std::cout << "Name: " << Serialization::deserialize(rawPtr)->s2 << std::endl;

    delete data;
    return EXIT_SUCCESS;
}
