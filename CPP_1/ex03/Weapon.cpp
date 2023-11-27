/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:54:47 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 17:26:06 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string& newType)
{
    this->type = newType;
}

void Weapon::setType(const std::string& newType)
{
    type = newType;
}

const std::string& Weapon::getType() const {
    return type;
}