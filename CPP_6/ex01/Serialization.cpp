/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:11:36 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 11:16:32 by feliciencat      ###   ########.fr       */
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

uintptr_t Serialization::serialize(Data* ptr)
{
    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    return (addr);
}

Data* Serialization::deserialize(uintptr_t raw)
{
    Data* pVar = reinterpret_cast<Data*>(raw);
    return(pVar);
}
