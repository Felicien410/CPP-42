/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:25:07 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:40:28 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type( "WrongAnimal" )
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) 
{
    std::cout << "[WrongAnimals]\t" << this->type << " constructor called" << std::endl;
    type = name;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimals]\tDestructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
    std::cout << "[WrongAnimals]\tCopy constructor called" << std::endl;
    this->type = cpy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& e)
{
    std::cout << "[WrongAnimals]\tCopy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->type = e.type;
    return(*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal]\tSome generic WrongAnimal sound" << std::endl;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->type;
}