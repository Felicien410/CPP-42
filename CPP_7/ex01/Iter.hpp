/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:25:31 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/24 10:44:57 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <class I>
void Iter(I tab[],int lenght, void (*f)(I))
{
    for(int i = 0; i < lenght ; i++)
    {
        f(tab[i]);
    }
    return;
}

#endif