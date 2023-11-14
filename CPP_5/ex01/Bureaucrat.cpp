/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:07:03 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/24 12:36:32 by feliciencat      ###   ########.fr       */
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

void Bureaucrat::signForm(std::string form_name, bool was_signed)
{
	if (was_signed)
		std::cout << this->getName() << " signed " << form_name << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form_name
			 << " because the grade was too low" << std::endl;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat & b)
{
    o << "[Bureaucrat]\t" << b.getName() << " bureaucrat grad "<< b.getGrade() << std::endl;
    return o;
}