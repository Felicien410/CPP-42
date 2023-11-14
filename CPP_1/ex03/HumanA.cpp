/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:13:44 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 17:23:41 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : c_weapon(type)
{
    c_Name = name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
    if (this->c_weapon.getType() != "")
    {
        std::cout << this->c_Name << " attacks with their " << c_weapon.getType() << std::endl;
    }
    else{
        std::cout << c_Name << " doesn't have a weapon to attack." << std::endl;
    }

}