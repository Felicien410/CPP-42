/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:47:19 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/14 08:53:31 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <class I> void print(I i)
{
    std::cout << i << std::endl;
}

int main()
{
    int tab[] = {0,1,2,3,4,5,6,7,8,9};
    std::string tab2[] = {"0","1","2","3","4","5","6","7","8","9"};
    std::string tab3[] = {"coucouc", "salut", "bonjour", "hello", "hi", "hola", "ciao", "hallo", "ni hao", "konichiwa"};
    Iter(tab, 10, print);
    std::cout << std::endl;
    Iter(tab2, 10, print);
    std::cout << std::endl;
    Iter(tab3, 10, print);
    return 0;
}