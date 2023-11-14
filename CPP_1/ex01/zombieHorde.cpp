/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:38 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/03 08:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;
	Zombie  *ptr_zombie;

	ptr_zombie = new (std::nothrow) Zombie[N];
    if (ptr_zombie == NULL )
        return (NULL);
    for (i = 0; i < N; i++)
    {
        ptr_zombie[i].setName(name);
    }
    return(ptr_zombie);

}
