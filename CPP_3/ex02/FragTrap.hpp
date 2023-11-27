/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:25:25 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 10:54:23 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include<iostream>
#include"ClapTrap.hpp"

const std::string ORANGE = "\033[38;5;208m";

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& cpy);
        FragTrap &operator=(const FragTrap& e);
        void guardGate();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif