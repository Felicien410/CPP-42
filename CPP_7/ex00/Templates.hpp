/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:38:58 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/24 10:45:06 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include<stdlib.h>
#include<string.h>
#include <iostream>

template <class T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
    return;
}

template <class Min> Min min(Min a, Min b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <class Max> Max max(Max a, Max b)
{
    if (a < b)
        return b;
    else
        return a;
}

#endif