/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:27:00 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/27 17:15:04 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>

class Span
{
    public:
        Span(unsigned int n);
        Span(Span const & src);
        ~Span(void);
        Span & operator=(Span const & rhs);
        
        void verifyLimit();
        void verifSize();

        void addNumber(int number);
        void addRange(int start, int end);
        long shortestSpan(void);
        long longestSpan(void);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void printElements();
        
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
        class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw()
                {
                    return ("No span to find");
                }
	    };
    private:
        Span();
        unsigned int _N;
		std::vector<int> storage;
};

#endif