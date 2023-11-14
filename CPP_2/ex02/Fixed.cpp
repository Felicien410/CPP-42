/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:00:44 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/27 17:02:30 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
    //std::cout << "Default constructor called" << std::endl;
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
    //std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->number_value = cpy.number_value;
}

Fixed &Fixed::operator=(const Fixed& e)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    this->number_value = e.number_value;
    return(*this);
}

int Fixed::getRawBits( void ) const
{
    //std::cout << "getRawBits member function called" << std::endl;
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

Fixed& Fixed::operator+=(const Fixed& a)
{
    number_value += a.number_value;
    return *this;
}

Fixed& Fixed::operator-=(Fixed const& a)
{
    number_value -= a.number_value;
    return *this;
}

Fixed& Fixed::operator*=(Fixed const& a)
{
    number_value *= a.number_value;
    return *this;   
}

Fixed& Fixed::operator/=(Fixed const& a)
{
    number_value /= a.number_value;
    return *this;
}

Fixed operator+(Fixed const& a, Fixed const& b)
{
    float floatValueA = a.toFloat();
    float floatValueB = b.toFloat();
    float result = floatValueA + floatValueB;
    return Fixed(result);
}

Fixed operator-(Fixed const& a, Fixed const& b)
{
    float floatValueA = a.toFloat();
    float floatValueB = b.toFloat();
    float result = floatValueA - floatValueB;
    return Fixed(result);
}

Fixed operator*(Fixed const& a, Fixed const& b)
{
    float floatValueA = a.toFloat();
    float floatValueB = b.toFloat();
    float result = floatValueA * floatValueB;
    return Fixed(result);
}

Fixed operator/(Fixed const& a, Fixed const& b)
{
    float floatValueA = a.toFloat();
    float floatValueB = b.toFloat();
    float result = floatValueA / floatValueB;
    return Fixed(result);
}

bool operator==(Fixed const& a, Fixed const& b)
{
    return a.estEgal(b);
}

bool operator!=(Fixed const& a, Fixed const& b)
{
    return (!a.estEgal(b));
}

bool operator>(Fixed const& a, Fixed const& b)
{
    return (a.isLonguer(b));
}

bool operator>=(Fixed const& a, Fixed const& b)
{
    return (a.isLonguer(b) || a.estEgal(b));
}

bool operator<=(Fixed const& a, Fixed const& b)
{
    return ((!a.isLonguer(b)) || a.estEgal(b));
}

bool operator<(Fixed const& a, Fixed const& b)
{
    return (!(a.isLonguer(b)));
}

bool Fixed::estEgal(Fixed const& b) const
{
    return (number_value == b.number_value);
}

bool Fixed::isLonguer(Fixed const& b) const
{
    return (number_value > b.number_value);
}

Fixed& Fixed::operator++()
{
    this->number_value += 1;  
    return *this;
}

Fixed& Fixed::operator--()
{
    this->number_value -= 1;  
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);       
    this->number_value += 1; 
    return temp;     
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);     
    this->number_value -= 1; 
    return temp;          
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return b;
    }
    return a;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
    if (a.getRawBits() < b.getRawBits())
    {
        return (a);
    }
    return (b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
    if (a.getRawBits() < b.getRawBits())
    {
        return (b);
    }
    return (a);
}
