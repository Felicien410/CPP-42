/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:27:12 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/22 12:05:18 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include"WrongAnimal.hpp"
#include"WrongCat.hpp"

int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    
    const int size = 10;
    Animal* tab[size];
    for (int i = 0; i < 5; i++)
    {
        tab[i] = new Dog();
    }
    for (int i = 5; i < size; i++)
    {
        tab[i] = new Cat();
    }
     
    for (int i = 0; i < size; i++)
    {
        tab[i]->makeSound();
    }

    for (int i = 0; i < size; i++)
    {
        delete(tab[i]);
    }
    return 0;
}