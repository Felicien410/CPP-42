/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:55:49 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/22 12:47:04 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AMateria.hpp"
#include"Character.hpp"

Character::Character(std::string const &n) : name(n)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    std::cout << "Character " << this->name << " initialized" << std::endl;
}

Character::~Character()
{
    std::cout << "Character " << this->name << " destroyed" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i])
        {
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& e)
{
    if (this == &e)
        return *this;

    this->name = e.name;
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = e.inventory[i];
    }
    return *this;
}

Character::Character(const Character& cpy)
{
    this->name = cpy.name;
    for (int i = 0; i < 4; i++)
    {
        delete this->inventory[i];
        if (cpy.inventory[i])
        {
            this->inventory[i] = cpy.inventory[i]->clone();
        }
        else
        {
            this->inventory[i] = NULL;
        }
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    int i = 0;

    while (i < 4)
    {
        if(this->inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << "Character " << this->name << " equipped with " << m->getType() << std::endl;
            return;
        }
    i++;
    }
    std::cout << "Character " << this->name << " can't equip " << m->getType() << std::endl;
    return;
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < 4 && inventory[idx] != NULL)
    {
        delete inventory[idx];
        inventory[idx] = NULL;
        std::cout << "Character " << this->name << " unequipped" << std::endl;
    }
    else
        std::cout << "Character " << this->name << " can nott be unequipe" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx >= 0 && idx <= 3)
    {
        if(inventory[idx] != NULL)
        {
            inventory[idx]->use(target);
            std::cout << "Character " << this->name << " uses " << this->inventory[idx]->getType() << std::endl;
        }
    }
    else
        std::cout << "Character " << this->name << " can't use" << std::endl;
}