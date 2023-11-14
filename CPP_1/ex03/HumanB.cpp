/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:11:23 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 17:25:19 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

HumanB::HumanB(std::string name)
{
    c_Name = name;
}

void HumanB::setWeapon(Weapon& weapon)
{
    m_weapon = &weapon;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (this->m_weapon != NULL && this->m_weapon->getType() != "") 
        std::cout << this->c_Name << " attacks with their " << m_weapon->getType() << std::endl;
    else
        std::cout << c_Name << " doesn't have a weapon to attack." << std::endl;
}