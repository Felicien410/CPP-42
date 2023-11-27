/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 08:39:58 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/22 12:33:01 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AMateria.hpp"

AMateria::AMateria()
{
    _type = "";
}

AMateria::AMateria(std::string const & type)
{
    _type = type;
    std::cout << "AMateria " << this->_type << " created" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (_type);
}

AMateria &AMateria::operator=(const AMateria& e)
{
    if (this == &e)
        return (*this);
    this->_type = e._type;
    return(*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria " << this->_type << " destroyed" << std::endl;
}

AMateria::AMateria(const AMateria& cpy)
{
    *this = cpy;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
