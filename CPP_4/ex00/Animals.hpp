/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:41:18 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:13:43 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include<iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal(std::string name);
        Animal();
        virtual ~Animal();
        Animal(const Animal& cpy);
        Animal &operator=(const Animal& e);
        virtual void makeSound() const;
        std::string     getType( void ) const; 
};

#endif