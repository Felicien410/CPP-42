/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:43 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 09:47:24 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie randomChump(std::string name)
{
    Zombie zomb = Zombie(name);
    zomb.annonce();
    return(zomb);
}
