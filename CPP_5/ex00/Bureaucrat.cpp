/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:07:03 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:12:21 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    _name = name;

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
{
    *this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& e)
{
    if (this == &e)
        return (*this);
    this->_grade = e._grade;
    this->_name = e._name;
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string  Bureaucrat::getName()
{
    return(this->_name);
}

int Bureaucrat::getGrade()
{
    return(this->_grade);
}

void Bureaucrat::increment_grade()
{
    if (_grade - 1  == 0)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrement_grade()
{
    if (_grade + 1 == 151)
        throw Bureaucrat::GradeTooHighException();
    _grade++;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat & b)
{
    o << b.getName() << " bureaucrat grad "<< b.getGrade() << std::endl;
    return o;
}
