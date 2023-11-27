/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:36:23 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/28 17:57:33 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Brain.hpp"

Brain::Brain()
{
    std::cout << "constructor Brain called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "[Brains]\tDestructor called" << std::endl;
}

Brain::Brain(const Brain& cpy)
{
    std::cout << "[Brains]\tCopy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = cpy.ideas[i];
    }
}

Brain &Brain::operator=(const Brain& e)
{
    std::cout << "[Brains]\tCopy assignment operator called" << std::endl;
    if (this == &e)
        return (*this);
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = e.ideas[i];
    }
    return(*this);
}