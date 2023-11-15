/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:28:02 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/14 15:25:42 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n), _size(0)
{
    _tab = new int[n];
}

Span::Span(Span const & src)
{
    *this = src;
}

Span::~Span(void)
{
    delete [] _tab;
}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        delete[] _tab;
        _n = rhs._n;
        _size = rhs._size;
        _tab = new int[_n];
        for (unsigned int i = 0; i < _size; ++i) {
            _tab[i] = rhs._tab[i];
        }
    }
    return *this;
}

void Span::verifySameNumber(int number)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        if (_tab[i] == number)
        {
            throw Span::SameValue();
        }      
    }
}

void Span::verifyLimit()
{
    if (_size >= _n)
        throw Span::Limit();
}

void Span::addNumber(int number)
{
    try {
        verifySameNumber(number);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    try {
        verifyLimit();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    _tab[_size] = number;
    _size++;
}

unsigned int Span::sizeElements()
{
    unsigned int count = 0;
    while (_tab[count] != 0) {
        count++;
    }
    return count;
}

void Span::verifSize()
{
    if (_size == 0 || _size == 1)
        throw Span::SizeLimit();
}

long Span::shortestSpan(void)
{
    if (_size == 0 || _size == 1)
        throw Span::SizeLimit();
    int *copy = new int[_size];
    std::copy(_tab, _tab + _size, copy);
    std::sort(copy, copy + _size);
    long long min = copy[1] - copy[0];
    for (unsigned int i = 0; i < _size - 1; i++)
    {
        if (copy[i + 1] - copy[i] < min)
            min = copy[i + 1] - copy[i];
    }
    delete [] copy;
    return (min);
}

long Span::longestSpan(void)
{
    if (_size == 0 || _size == 1)
        throw Span::SizeLimit();
    int *copy = new int[_size];
    std::copy(_tab, _tab + _size, copy);
    std::sort(copy, copy + _size);

    long long max = copy[_size - 1] - copy[0];
    delete [] copy;
    return (max);
}

void Span::addNumbers(int begin, int end)
{
    try {
        verifyLimit();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
        return ;
    }
    if (begin > end)
    {
        int tmp = begin;
        begin = end;
        end = tmp;
    }
    for (int i = begin; i <= end; i++)
    {
        addNumber(i);
    }
}

void Span::printElements()
{
    std::cout << "Elements: [";
    for (unsigned int i = 0; i < _size; i++)
    {   
        std::cout << _tab[i];
        if (i != _size - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
