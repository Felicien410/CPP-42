/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:19 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/26 14:13:10 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

        
        typedef void (Harl::*fonctions)();
        
    public:
        void complain( std::string level );
        Harl();
        ~Harl();
        
};

#endif