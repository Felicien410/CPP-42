/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:11:36 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/23 09:16:51 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
}

Serialization::Serialization(const Serialization & src)
{
    *this = src;
}

Serialization::~Serialization()
{
}

Serialization & Serialization::operator=(const Serialization & rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}

unsigned long Serialization::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

Data* Serialization::deserialize(unsigned long raw) {
    return reinterpret_cast<Data*>(raw);
}
