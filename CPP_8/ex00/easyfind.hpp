/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:21 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/14 13:23:03 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<string.h>

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <class T>
int easyFind(T tab, int number)
{
    for ( unsigned long i = 0; i < tab.size(); i++)
    {
        if (tab[i] == number)
            return (i);
    }
    return (-1);
}

#endif