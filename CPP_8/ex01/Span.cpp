/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:28:02 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/27 17:07:43 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _N(n)
{
}

Span::Span(void) : _N(0)
{
}

Span::Span(Span const & src)
{
    *this = src;
}

Span::~Span(void)
{
}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        this->_N = rhs._N;
        this->storage = rhs.storage;
    }
    return *this;
}

void Span::verifyLimit()
{
    if (this->storage.size() == this->_N)
        throw Span::Limit();
}

void Span::verifSize()
{
    if (this->storage.size() < 2)
        throw Span::SizeLimit();
    
}

void Span::addNumber(int number)
{
    if(_N == 0)
        throw Span::NoSpanException();
    if (storage.size() + 1 > this->_N)
        throw Span::Limit();
    this->storage.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(_N == 0)
        throw Span::NoSpanException();        
    if (this->storage.size() + std::distance(begin, end) > this->_N)
        throw Span::Limit();
    this->storage.insert(this->storage.end(), begin, end);
}

void Span::addRange(int start, int end)
{
    if (start > end)
        std::swap(start, end);
    if(_N == 0)
        throw Span::NoSpanException();
    if (this->storage.size() + (end - start) > this->_N)
        throw Span::Limit();
    for (int i = start; i <= end; i++)
        this->storage.push_back(i);
}

void Span::printElements()
{
    for (std::vector<int>::iterator it = this->storage.begin(); it != this->storage.end(); it++)
        std::cout << *it << std::endl;
}

long Span::shortestSpan(void)
{
    if(_N == 0)
        throw Span::NoSpanException();
    verifSize();

    std::vector<int> tmp = this->storage;
    std::sort(tmp.begin(), tmp.end());
    long shortest = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
    {
        if (shortest > *(it + 1) - *it)
            shortest = *(it + 1) - *it;
    }
    return shortest;
}

long Span::longestSpan(void)
{
    if(_N == 0)
        throw Span::NoSpanException();
    verifSize();

    std::vector<int> tmp = this->storage;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}


