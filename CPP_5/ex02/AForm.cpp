/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:43:47 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:13:34 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExcecute )
: _name(name), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExcecute(gradeRequiredToExcecute)
{
    std::cout << "AForm constructor called with name: " << name << ", gradeRequiredToSign: " << gradeRequiredToSign << ", gradeRequiredToExcecute: " << gradeRequiredToExcecute << std::endl;
    _is_signed = 0;
    if (_gradeRequiredToSign < 1 || _gradeRequiredToSign > 150)
        throw AForm::GradeTooHighException();
    if (_gradeRequiredToExcecute < 1 || _gradeRequiredToExcecute > 150)
        throw AForm::GradeTooLowException();
}


AForm::~AForm()
{
    std::cout << "AForm destructor called for " << _name << std::endl;
}

AForm::AForm(const AForm& cpy) 
    :  _name(cpy._name),
      _gradeRequiredToSign(cpy._gradeRequiredToSign), 
      _gradeRequiredToExcecute(cpy._gradeRequiredToExcecute)
{
    std::cout << "AForm copy constructor called for " << cpy._name << std::endl;
    this->_is_signed = cpy._is_signed;
}


AForm &AForm::operator=(const AForm& e)
{
    std::cout << "AForm assignment operator called for " << e._name << std::endl;
    if (this == &e)
        return (*this);
    this->_is_signed = e._is_signed;
    return (*this);
}

std::string AForm::getName() const
{
    return(this->_name);
}

int AForm::get_is_signed() const
{
    return(this->_is_signed);
} 

int AForm::get_gradeRequiredToExcecute() const
{
    return(this->_gradeRequiredToExcecute);
} 

int AForm::get_gradeRequiredToSign() const
{
    return(this->_gradeRequiredToSign);
} 

std::ostream & operator<<( std::ostream & o, AForm & b)
{
    o << "[AForm]\t" << b.getName() << " state of the signature " <<
        b.get_is_signed() << " grade Required To Sign : " << b.get_gradeRequiredToSign() <<
        "grade Required To Excecute : " << b.get_gradeRequiredToExcecute() << std::endl;
    return o;
}

void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() >= get_gradeRequiredToExcecute())
    {
        b.signForm(this->getName(), this->_is_signed);
        throw AForm::GradeTooLowException();
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

void AForm::execute(Bureaucrat const & b) const
{
    if (b.getGrade() > get_gradeRequiredToExcecute())
        throw AForm::GradeTooLowException();
    else if (get_is_signed() == false)
        std::cout << "AForm couldn't be executed by " << b.getName() << " because it wasn't signed!" << std::endl;
    else
    {
        std::cout << "[Form]    Document executed by "<< b.getName() << std::endl;
        extra_message(const_cast<Bureaucrat&>(b));
    }
}
