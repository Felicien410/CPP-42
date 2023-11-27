/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:38 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 09:47:14 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *zomb_ptr = new Zombie(name);
    if (!zomb_ptr)
        return(NULL);
    zomb_ptr->annonce();
    return(zomb_ptr);
}