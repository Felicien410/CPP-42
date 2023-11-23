/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:34:05 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/23 09:08:27 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cerrno>
#include <sstream>
#include <cfloat>
#include <limits>

class ScalarConverter
{
    public:
        ScalarConverter(std::string str);
        ScalarConverter(const ScalarConverter & src);
        ~ScalarConverter();
        ScalarConverter & operator=(const ScalarConverter & rhs);
        static void convert(std::string& _str);
        static void printConvertedValues(char cVal, long iVal, float fVal, double dVal);
        std::string getStr() const;
    
    private:
        ScalarConverter();
        std::string _str;

};


int     isInt(std::string &literal);
int     isFloat(std::string &literal);
int     isChar(std::string &literal);
int     isDouble(std::string &literal);
int handleSpecialLiterals(std::string &literal);

#endif
