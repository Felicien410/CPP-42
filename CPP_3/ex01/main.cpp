/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:47:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/13 07:24:55 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

int main()
{
    ClapTrap a("Jhonny");
    ClapTrap b("Polnareff");
    ScavTrap c("Scalvitie");
    c.guardGate();
    b.attack("Jhonny");
    a.takeDamage(0);
    a.attack("Polnareff");
    b.takeDamage(0);
    b.beRepaired(5);
    a.attack("Scalvitie");
    c.takeDamage(0);
    b.attack("Scalvitie");
    c.takeDamage(0);
    c.attack("Johnny");
    a.takeDamage(20);
    a.attack("Scalvitie");
    return (0);
}