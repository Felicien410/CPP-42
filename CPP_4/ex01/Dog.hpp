/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:41:18 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 17:40:42 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include"Animals.hpp"
#include"Brain.hpp"

class Dog : public Animal
{

    public:
        Dog();
        ~Dog();
        Dog(const Dog& cpy);
        Dog &operator=(const Dog& e);
        virtual void makeSound() const;

    private:
        Brain* Dog_Brain;
};

#endif