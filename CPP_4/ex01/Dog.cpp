/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:44:20 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/22 12:12:51 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "[" << this->type << "]\t" << " constructor called" << std::endl;
    try {
        Dog_Brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Memory Allocation is failed : " << e.what() << std::endl;
    }
}

Dog::~Dog()
{
    delete this->Dog_Brain;
    std::cout << "[" << this->type << "]\t" << " destructor called" << std::endl;

}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
    std::cout << "[" << this->type << "]\t" << "copy constructor called" << std::endl;
    this->type = cpy.type;
    Dog_Brain = new Brain(*(cpy.Dog_Brain)); 
}

Dog &Dog::operator=(const Dog& e)
{
    std::cout << "[" << this->type << "]\t" << "Copy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->type = e.type;
    delete Dog_Brain;
    Dog_Brain = new Brain(*(e.Dog_Brain));
    return(*this);
}

void Dog::makeSound() const {
    std::cout << "[" << this->type << "]\t\t" << "Wouf Wouf" << std::endl;
}