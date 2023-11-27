/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:41:18 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 16:43:02 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include"Animals.hpp"

class Dog : public Animal
{

    public:
        Dog();
        ~Dog();
        Dog(const Dog& cpy);
        Dog &operator=(const Dog& e);
        virtual void makeSound() const;
};

#endif