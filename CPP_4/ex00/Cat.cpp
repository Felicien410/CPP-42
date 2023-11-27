/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:44:20 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:14:28 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "[Cat]\t" << this->type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "[Cat]\tDestructor called" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    std::cout << "[Cat]\tCopy constructor called" << std::endl;
    this->type = cpy.type;
}

Cat &Cat::operator=(const Cat& e)
{
    std::cout << "[Cat]\tCopy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->type = e.type;
    return(*this);
}

void Cat::makeSound() const {
    std::cout << "[Cat]\tMiaw Miaw" << std::endl;
}