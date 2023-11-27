/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:57:09 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 14:41:11 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int main()
{
	Zombie	*ptr_zombie;
	int i;

	ptr_zombie = zombieHorde(4, "fel");
	if(!ptr_zombie)
		return(1);
	for (i = 0; i < 4; i++)
	{
		ptr_zombie[i].annonce();
	}
	delete [] ptr_zombie;
	return (0);
}
