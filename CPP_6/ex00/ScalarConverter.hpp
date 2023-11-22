/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:34:05 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 11:14:08 by feliciencat      ###   ########.fr       */
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

// creat a static class ScalarConverter
class ScalarConverter
{
    public:
        ScalarConverter(std::string str);
        ScalarConverter(const ScalarConverter & src);
        ~ScalarConverter();
        ScalarConverter & operator=(const ScalarConverter & rhs);
        
        void convert();
        void printConvertedValues();
        std::string getStr() const;
        void setStr(std::string str);

    private:
        ScalarConverter();
        std::string _str;
        long _iVal;
        float   _fVal;
        double  _dVal;
        char    _cVal;
};
#endif

int     isInt(std::string &literal);
int     isFloat(std::string &literal);
int     isChar(std::string &literal);
int     isDouble(std::string &literal);
int handleSpecialLiterals(std::string &literal);

