/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:29:11 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:44:00 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") 
{
    std::cout << "[WrongCat]\t" << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat]\tDestructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "[WrongCat]\tMiaw Miaw" << std::endl;
}