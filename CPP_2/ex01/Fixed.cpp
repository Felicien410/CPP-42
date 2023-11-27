/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:00:44 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/27 08:58:07 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number_value = 0;
}

Fixed::Fixed(const int i)
{
    this->number_value = i << fractinal_bits;
}

Fixed::Fixed(const float f)
{
    this->number_value = roundf(f * (1 << fractinal_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->number_value = cpy.number_value;
}

Fixed &Fixed::operator=(const Fixed& e)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->number_value = e.number_value;
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

float Fixed::toFloat(void) const
{
    return static_cast<float>(number_value) / (1 << fractinal_bits);
}

int Fixed::toInt(void) const
{
    return number_value >> fractinal_bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}