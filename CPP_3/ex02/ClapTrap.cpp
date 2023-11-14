/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:16:17 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/13 07:32:37 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap& cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_attack_damage = cpy._attack_damage;
    this->_energy_points = cpy._energy_points;
    this->_hit_points = cpy._hit_points;
    this->_name = cpy._name;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& e)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->_attack_damage = e._attack_damage;
    this->_energy_points = e._energy_points;
    this->_hit_points = e._hit_points;
    this->_name = e._name;
    return(*this);
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << BOLD << BLUE << "[ClapTrap] 🤖\tDefault constructor called for " << WHITE << _name << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[ClapTrap] " << WHITE << _name << " is dead! 😢" << RESET << std::endl;
        return;
    }
    if (this->_energy_points <= 0)
    {
        std::cout << BOLD << BLUE << "[ClapTrap] " << WHITE << _name << " is out of energy! 😢" << RESET << std::endl;
        return;
    }
    std::cout << BOLD << BLUE << "[ClapTrap] 🗡️\t" << WHITE << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage! 💥 " << "Energy left: " << _energy_points - 1 << RESET << std::endl;
    _energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points <= amount)
    {
        _hit_points = 0;
        std::cout << BOLD << BLUE << "[ClapTrap] " << WHITE << _name << " is already dead 😵" << RESET << std::endl;
        return;
    }
    _hit_points -= amount;
    std::cout << BOLD << BLUE << "[ClapTrap] 💥\t" << WHITE << _name << " took damage, causing " << amount << " points of damage! Energy left: " << _energy_points << RESET << std::endl;}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[ClapTrap] " << WHITE << _name << " is dead! 😢" << RESET << std::endl;
        return;
    }
    if (_energy_points <= amount)
    {
        std::cout << BOLD << BLUE << "[ClapTrap] " << WHITE << _name << " is out of energy! 😢" << RESET << std::endl;
        return;
    }
    _energy_points -= 1;
    _hit_points += amount;
    std::cout << BOLD << BLUE << "[ClapTrap] 💚\t" << WHITE << _name << " repaired itself, gaining " << amount << " points of health! Energy left: " << _energy_points << RESET << std::endl;
    std::cout << BOLD << BLUE << "[ClapTrap] ❤️ \t" << WHITE << _name << " new hitpoints: " << _hit_points << RESET << std::endl;
}
