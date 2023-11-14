/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:50:39 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/11 11:57:58 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"
FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 30;
    std::cout << BOLD << ORANGE << "[FragTrap] 🤖\tDefault constructor called for " << WHITE << _name << RESET << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << BOLD << ORANGE << "[FragTrap] Destructor called PFIOUUUUUUU 💨" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& e)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    ClapTrap::operator=(e); // Call to the base class assignment operator
    return (*this);
}

void FragTrap::guardGate()
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[FragTrap] " << WHITE << _name << " is already dead! 😢" << RESET << std::endl;
        return;
    }
    std::cout << BOLD << ORANGE << "[FragTrap] 🛡️\t" << _name << " is now in Gate keeper mode." << RESET << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[FragTrap] " << WHITE << _name << " is dead! 😢" << RESET << std::endl;
        return;
    }
    if(this->_energy_points <= 0)
    {
        std::cout << BOLD << ORANGE << "[FragTrap]\t" << WHITE << _name << " is out of energy! 😢" << RESET << std::endl;
        return;
    }
    std::cout << BOLD << ORANGE << "[FragTrap] 🗡️\t" << WHITE << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage! OMG WTF 🚀" << " Energy left: " << _energy_points - 1 << RESET << std::endl;
    _energy_points -= 1;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hit_points <= 0)
    {
        std::cout << BOLD << BLUE << "[FragTrap] " << WHITE << _name << " is dead! 😢" << RESET << std::endl;
        return;
    }
    std::cout << BOLD << ORANGE << "[FragTrap]  🙏\tGive me a high five please, guys :((." << RESET << std::endl;
}





