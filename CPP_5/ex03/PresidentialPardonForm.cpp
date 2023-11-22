/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:33:20 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:15:17 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
    _target = target;
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm("PresidentialPardonForm", 25, 5)
{
    *this = cpy;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& e)
{
    if (this == &e)
        return (*this);
    this->_target = e._target;
    return (*this);
}

void PresidentialPardonForm::extra_message(Bureaucrat& b) const
{
    if (b.getGrade() > get_gradeRequiredToExcecute())
        throw AForm::GradeTooLowException();
    else if (get_is_signed() == false)
        std::cout << "PresidentialPardonForm couldn't be executed by " << b.getName() << " because it wasn't signed!" << std::endl;
    else
        std::cout << "[Information] " << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
