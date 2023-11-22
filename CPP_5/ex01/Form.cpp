/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:43:47 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:12:50 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExcecute )
: _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExcecute(gradeRequiredToExcecute)
{
    _is_signed = 0;
    if (_gradeRequiredToSign < 1 || _gradeRequiredToSign > 150)
        throw Form::GradeTooHighException();
    if (_gradeRequiredToExcecute < 1 || _gradeRequiredToExcecute > 150)
        throw Form::GradeTooLowException();
}


Form::~Form()
{
}

Form::Form(const Form& cpy) 
    :  _name(cpy._name),
      _gradeRequiredToSign(cpy._gradeRequiredToSign), 
      _gradeRequiredToExcecute(cpy._gradeRequiredToExcecute)
{
    this->_is_signed = cpy._is_signed;
}


Form &Form::operator=(const Form& e)
{
    if (this == &e)
        return (*this);
    this->_is_signed = e._is_signed;
    return (*this);
}

std::string Form::getName()
{
    return(this->_name);
}

int Form::get_is_signed()
{
    return(this->_is_signed);
} 

int Form::get_gradeRequiredToExcecute()
{
    return(this->_gradeRequiredToExcecute);
} 

int Form::get_gradeRequiredToSign()
{
    return(this->_gradeRequiredToSign);
} 

std::ostream & operator<<( std::ostream & o, Form & b)
{
    o << "[Form]\t" << b.getName() << " state of the signature " <<
        b.get_is_signed() << " grade Required To Sign : " << b.get_gradeRequiredToSign() <<
        "grade Required To Excecute : " << b.get_gradeRequiredToExcecute() << std::endl;
    return o;
}

void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() >= get_gradeRequiredToExcecute())
    {
        b.signForm(this->getName(), this->_is_signed);
        throw Form::GradeTooLowException();
    }
    if (get_is_signed() == 1)
    {
        std::cout << "[Form]    Document already signed" << std::endl;
    }
    else
    {
        std::cout << "[Form]    Document signed by "<< b.getName() << std::endl;
        _is_signed = 1;
    }
}

