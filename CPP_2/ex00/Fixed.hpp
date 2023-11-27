/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:19 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 09:26:47 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int number_value;
        static const int fractinal_bits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed& cpy);
        Fixed &operator=(const Fixed& e);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif