/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:41:18 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 18:14:57 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include"Animals.hpp"
#include"Brain.hpp"

class Cat : public Animal
{

    public:
        Cat();
        ~Cat();
        Cat(const Cat& cpy);
        Cat &operator=(const Cat& e);
        virtual void makeSound() const;

    private:
        Brain* Cat_Brain;
};

#endif