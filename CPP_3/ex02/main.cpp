/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:47:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 11:20:57 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"

int main()
{
    ClapTrap a("Jhonny");
    ClapTrap b("Polnareff");
    ScavTrap c("Scalvitie");
    FragTrap d("Gilbert Montagné");
    
    std::cout << BOLD << WHITE << "\n🔥 The sky is overcast. A cold wind sweeps the battlefield as our warriors prepare for the ultimate showdown. 🔥\n" << RESET;
    std::cout << "\nJhonny and Polnareff face off in a fierce showdown.\n";
    a.attack("Polnareff");
    b.takeDamage(0);
    b.attack("Jhonny");
    a.takeDamage(0);
    std::cout << "\nScalvitie  arrives on the battlefield with his mega baldness.\n";
    c.guardGate();
    std::cout << "\nIn the midst of battle, Gilbert shouts out, But he doesn't see anything because he is blind\n";
    d.highFivesGuys();
    std::cout << "\nPolnareff, seeing the disadvantage, retreats slightly to gather his strength.\n";
    b.beRepaired(5);
    std::cout << "\nJhonny, sensing an opportunity, charges at Scalvitie.\n";
    a.attack("Scalvitie");
    c.takeDamage(0);
    std::cout << "\nScalvitie retaliates with fury against Jhonny's audacity.\n";
    c.attack("Jhonny");
    a.takeDamage(20);
    std::cout << BOLD << WHITE << "\n💥 The battlefield goes silent as the dust settles. Warriors, exhausted and wounded, await the declaration of the victor. 💥\n" << RESET;
    return (0);
}