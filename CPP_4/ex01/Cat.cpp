/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:44:20 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/22 12:10:51 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
    std::cout << "[" << this->type << "]\t" << " constructor called" << std::endl;
    try {
        Cat_Brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Cat::~Cat()
{
    delete this->Cat_Brain;
    std::cout << "[" << this->type << "]\t" << " destructor called" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    std::cout << "[" << this->type << "]\t" << " copy constructor called" << std::endl;
    this->type = cpy.type;
}

Cat &Cat::operator=(const Cat& e)
{
    std::cout << "[" << this->type << "]\t" << " Copy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->type = e.type;
    return(*this);
}

void Cat::makeSound() const {
    std::cout << "[" << this->type << "]\t" << "\tMiaw Miaw" << std::endl;
}