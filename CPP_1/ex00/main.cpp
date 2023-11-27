/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:57:09 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 09:48:20 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int main()
{
	Zombie	*ptr_zombie;

	ptr_zombie = new Zombie("foo");
	if (!ptr_zombie)
		return (1);
	ptr_zombie->annonce();
	delete ptr_zombie;
	randomChump("Donald");
	return (0);
}