/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutanstack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:45:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/15 12:43:02 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include<iostream>

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

template <typename T>
class MutantStack : public std::stack<T>
{
    public :
        MutantStack();
        MutantStack(MutantStack const & src);
        ~MutantStack();
        MutantStack & operator=(MutantStack const & rhs);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
        void printStack();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src)
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs)
{
    if (this != &rhs)
        std::stack<T>::operator=(rhs);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template <typename T>
void MutantStack<T>::printStack()
{
    typename MutantStack<T>::iterator it = this->begin();
    typename MutantStack<T>::iterator ite = this->end();
    while (it != ite)
    {
        std::cout << "[" << *it << "] ";
        it++;
    }
    std::cout << std::endl;
}

#endif