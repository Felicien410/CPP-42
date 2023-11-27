/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:28:12 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/25 15:36:48 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string line = "HI THIS IS BRAIN";
    std::string *stringpPTR = &line;
    std::string& stringREF = line;

    std::cout << &line << std::endl;
    std::cout << stringpPTR << std::endl;
    std::cout << &stringREF << std::endl;
    
    std::cout << line << std::endl;
    std::cout << *stringpPTR << std::endl;
    std::cout << stringREF << std::endl;
}