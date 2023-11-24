/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:19:14 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/24 13:56:22 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyfind.hpp"
#include<vector>

int main()
{
    std::vector<int> tab;
    tab.push_back(13);
    tab.push_back(25);
    tab.push_back(333);
    std::cout << easyFind(tab, 2) << std::endl;
    std::cout << easyFind(tab, 333) << std::endl;
}