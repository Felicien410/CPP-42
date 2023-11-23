/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:33:50 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/23 09:08:30 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
std::atoi: Comme en C, elle convertit une chaîne en un entier (int). Elle est définie dans l'en-tête <cstdlib>.

std::atol: Convertit une chaîne en un entier long (long int). Elle est également définie dans <cstdlib>.

std::atof: Convertit une chaîne en un double (double). 
Trouvée dans <cstdlib> aussi.

std::strtol: Convertit une chaîne en un entier long (long int),
 tout en permettant plus de contrôle sur le processus de conversion (par exemple, choix de la base). Déclarée dans <cstdlib>.

std::strtoul: Convertit une chaîne en un entier long non signé (unsigned long int).
 Elle est aussi définie dans <cstdlib>.

std::strtod: Convertit une chaîne en un double (double),
similaire à std::atof mais avec des fonctionnalités supplémentaires, comme std::strtol. Également dans <cstdlib>.
*/

ScalarConverter::ScalarConverter(std::string str) : _str(str)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter & src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & rhs)
{
    if (this != &rhs)
    {
        this->_str = rhs._str;
    }
    return (*this);
}

static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

std::string ScalarConverter::getStr() const
{
    return _str;
}


static double ft_stod(const std::string& str)
{
    double num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

void ScalarConverter::convert(std::string& _str) {

    char _cVal = '\0';
    long _iVal = 0;
    float _fVal = 0.0f;
    double _dVal = 0.0;
    
    int (*checkFunctions[5])(std::string &_str) = {&isChar, &isInt, &isDouble, &isFloat, &handleSpecialLiterals};

    for (int i = 0; i < 5; i++) {
        if (checkFunctions[i](_str)) {
            try {
                switch (i) {
                    case 0: // Char
                        _cVal = _str[0];
                        _iVal = static_cast<int>(_cVal);
                        _dVal = static_cast<double>(_cVal);
                        _fVal = static_cast<float>(_cVal);
                        break;
                    case 1: // Int
                        _iVal = ft_stoi(_str);
                        _fVal = static_cast<float>(_iVal);
                        _dVal = static_cast<double>(_iVal);
                        _cVal = static_cast<char>(_iVal);
                        break;
                    case 2: // Double
                        _dVal = ft_stod(_str);
                        _fVal = static_cast<float>(_dVal);
                        _iVal = static_cast<int>(_dVal);
                        _cVal = static_cast<char>(_dVal);
                        break;
                    case 3: // Float
                        _fVal = ft_stof(_str);
                        _dVal = static_cast<double>(_fVal);
                        _iVal = static_cast<int>(_fVal);
                        _cVal = static_cast<char>(_fVal);
                        break;
                    case 4: // Special literals
                        handleSpecialLiterals(_str);
                        break;
                }
            } catch (const std::exception& e) {
                std::cout << "char: Impossible" << std::endl;
                std::cout << "int: Impossible" << std::endl;
                std::cout << "float: Impossible" << std::endl;
                std::cout << "double: Impossible" << std::endl;
                return;
            }
            break;
        }
    }
    printConvertedValues(_cVal, _iVal, _fVal, _dVal);
}

void ScalarConverter::printConvertedValues(char _cVal, long _iVal, float _fVal, double _dVal)
{
    std::cout << "char: "; 
    if ((_cVal >= 32 && _cVal <= 47) || (_cVal >= 58 && _cVal <= 126))
        std::cout << "'" <<  _cVal << "'" << std::endl;
    else if (_cVal < 32 || _cVal > 126 || (_cVal >= 48 && _cVal <= 57))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

   std::cout << "int: ";
    if (_iVal >= INT_MIN && _iVal <= INT_MAX)
        std::cout << _iVal << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (_fVal >= -FLT_MIN && _fVal <= FLT_MAX)
    {
        if (_iVal == _fVal)
            std::cout << _fVal << ".0f" << std::endl;
        else
            std::cout << _fVal << "f" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    
    std::cout << "double: ";
    if (_dVal >= -DBL_MIN && _dVal <= DBL_MAX)
    {
        if (_dVal == _fVal)
            std::cout << _dVal << ".0" << std::endl;
        else
            std::cout << _dVal << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

int     isInt(std::string &literal)
{
    int i = 0;
    int dot = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (literal[i])
    {
        if ((literal[i] == 'e' || literal[i] == 'E') && !isdigit(literal[i]))
        {
            dot++;
            i++;
            if (literal[i] == '+')
                i++;
        }
        else if (!isdigit(literal[i]) || literal[i] == '-')
        {
            return (0);
        }
        else
            i++;
    }
    if (dot > 1)
        return (0);
    return (1);
}

int     isDouble(std::string &literal)
{
    int i = 0;
    int dot = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (literal[i])
    {
        if (literal[i] == '.')
            dot++;
        else if (!isdigit(literal[i]))
            return (0);
        i++;
    }
    if (dot > 1)
        return (0);
    return (1);
}

int     isFloat(std::string &literal)
{
    int i = 0;
    int dot = 0;
    int dot2 = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    while (literal[i])
    {
        if (literal[i] == 'e' || literal[i] == 'E')
        {
            dot2++;
            i++;
            if (literal[i] == '-')
                i++;
        }
        if (literal[i] == '.')
        {
            i++;
            dot++;
        }
        if ((literal[i] == 'f' || literal[i] == 'F') && (size_t)(i + 1) == literal.size())
        {
            i++;
            continue;
        }
        if (!isdigit(literal[i++]))
            return (0);
    }
    if (dot > 1 || dot2 > 1)
        return (0);
    return (1);
}

int     isChar(std::string &literal)
{
    if (literal.length() == 1 && isprint(literal[0]))
        return (1);
    return (0);
}

int handleSpecialLiterals(std::string &literal)
{
    if (literal == "inf" || literal == "inff" || literal == "infl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "inff" << std::endl;
        std::cout << "double: " << "inf" << std::endl;
        exit(0);
    }
    else if (literal == "-inf" || literal == "-inff" || literal == "-infl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
        exit(0);
    }
    else if (literal == "nan" || literal == "nanf" || literal == "nanl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
        exit(0);
    }
    else if (literal == "-nan" || literal == "-nanf" || literal == "-nanl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "-nanf" << std::endl;
        std::cout << "double: " << "-nan" << std::endl;
        exit(0);
    }
    else if (literal == "+inf" || literal == "+inff" || literal == "+infl")
    {
        std::cout << "char: infinity" << std::endl;
        std::cout << "int: infinity" << std::endl;
        std::cout << "float: infinity" << std::endl;
        std::cout << "double: infinity" << std::endl;
        exit(0);
    }
    else if (literal == "+nan" || literal == "+nanf" || literal == "+nanl")
    {
        std::cout << "char: nan" << std::endl;
        std::cout << "int: nan" << std::endl;
        std::cout << "float: nan" << std::endl;
        std::cout << "double: nan" << std::endl;
        exit(0);
    }
    else
    {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        std::cout << "float: Impossible" << std::endl;
        std::cout << "double: Impossible" << std::endl;
        exit(0);
    }
    return (0);
}

