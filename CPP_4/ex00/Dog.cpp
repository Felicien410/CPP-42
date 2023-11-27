/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:44:20 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:13:02 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << this->type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[Dog]\tDestructor called" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
    std::cout << "[Dog]\tCopy constructor called" << std::endl;
    this->type = cpy.type;
}

Dog &Dog::operator=(const Dog& e)
{
    std::cout << "[Dog]\tCopy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->type = e.type;
    return(*this);
}

void Dog::makeSound() const {
    std::cout << "[Dog]\tWouf Wouf" << std::endl;
}