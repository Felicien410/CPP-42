/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:27:00 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/23 09:33:15 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<string.h>
#include<algorithm>

class Span
{
    public:
        Span(unsigned int n);
        Span(Span const & src);
        ~Span(void);
        Span & operator=(Span const & rhs);
        
        void verifySameNumber(int number);
        void verifyLimit();
        void verifSize();

        void addNumber(int number);
        long shortestSpan(void);
        long longestSpan(void);
        void addNumbers(int begin, int end);
        unsigned int sizeElements();
        void printElements();
        
        class SameValue : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("You can't set the same value twice.");
                }
        };
        class Limit : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("You can't add more elements.");
                }
        };
        class SizeLimit : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Distance can't be calculated");
                }
        };
    private:
        Span(void);
        unsigned int _n;
        unsigned int _size;
        int *_tab;
};

#endif