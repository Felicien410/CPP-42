/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:44:20 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:14:13 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animals.hpp"

Animal::Animal() : type( "Animal" )
{
    std::cout << this->type << " constructor called" << std::endl;
}

Animal::Animal(std::string name)
{
    std::cout << "[Animals]\t" << this->type << " constructor called" << std::endl;
    type = name;
}

Animal::~Animal()
{
    std::cout << "[Animals]\tDestructor called" << std::endl;
}

Animal::Animal(const Animal& cpy)
{
    std::cout << "[Animals]\tCopy constructor called" << std::endl;
    this->type = cpy.type;
}

Animal &Animal::operator=(const Animal& e)
{
    std::cout << "[Animals]\tCopy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->type = e.type;
    return(*this);
}

void Animal::makeSound() const {
    std::cout << "[Animal]\tSome generic animal sound" << std::endl;
}

std::string    Animal::getType( void ) const
{
    return this->type;
}