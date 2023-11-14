/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:31:39 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/11 11:57:10 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << BOLD << MAGENTA << "[ScavTrap] 🤖\tDefault constructor called for " << WHITE << _name << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << BOLD << MAGENTA << "[ScavTrap] Destructor called PFIOUUUUUUU 💨" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(cpy)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& e)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    ClapTrap::operator=(e); // Appel à l'opérateur d'assignation de la classe de base
    return (*this);
}

void ScavTrap::guardGate()
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[ScavTrap] " << WHITE << _name << " is already dead! 😢" << RESET << std::endl;
        return;
    }
    std::cout << BOLD << MAGENTA << "[ScavTrap] 🛡️\t" << _name << " is now in Gate keeper mode." << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[ScavTrap] " << WHITE << _name << " is already dead! 😢" << RESET << std::endl;
        return;
    }
    if(this->_energy_points <= 0)
    {
        std::cout << BOLD << MAGENTA << "[ScavTrap]\t" << WHITE << _name << " is out of energy! 😢" << RESET << std::endl;
        return;
    }
    std::cout << BOLD << MAGENTA << "[ScavTrap] 🗡️\t" << WHITE << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage! OMG WTF 🚀" << " Energy left: " << _energy_points - 1 << RESET << std::endl;
    _energy_points -= 1;
}