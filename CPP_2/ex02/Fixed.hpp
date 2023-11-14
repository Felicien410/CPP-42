/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:19 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/06 11:29:13 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int number_value;
        static const int fractinal_bits = 8;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& cpy);
        Fixed &operator=(const Fixed& e);
        Fixed(const int i);
        Fixed(const float f);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        //operators
        bool estEgal(Fixed const& b) const;
        bool isLonguer(Fixed const& b) const;
        Fixed& operator+=(Fixed const& a);
        Fixed& operator-=(Fixed const& a);
        Fixed& operator*=(Fixed const& a);
        Fixed& operator/=(Fixed const& a);
        Fixed& operator++();     
        Fixed operator++(int);   
        Fixed& operator--();       
        Fixed operator--(int);
        
        static Fixed const& min(Fixed const& a, Fixed const& b);
        static Fixed const& max(Fixed const& a, Fixed const& b);
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );
bool operator==(Fixed const& a, Fixed const& b);
bool operator!=(Fixed const& a, Fixed const& b);
bool operator>(Fixed const& a, Fixed const& b);
bool operator<(Fixed const& a, Fixed const& b);
bool operator>=(Fixed const& a, Fixed const& b);
bool operator<=(Fixed const& a, Fixed const& b);

Fixed operator+(Fixed const& a, Fixed const& b);
Fixed operator-(Fixed const& a, Fixed const& b);
Fixed operator*(Fixed const& a, Fixed const& b);
Fixed operator/(Fixed const& a, Fixed const& b);


