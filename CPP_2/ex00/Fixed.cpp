/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:00:44 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/03 09:20:31 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number_value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(cpy.getRawBits());
}

Fixed &Fixed::operator=(const Fixed& e)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->setRawBits(e.getRawBits());
    return(*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->number_value);
}

void Fixed::setRawBits( int const raw )
{
    this->number_value = raw;
}
