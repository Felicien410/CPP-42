/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:19 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/06 11:28:10 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP

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
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif