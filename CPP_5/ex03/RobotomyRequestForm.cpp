/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:50:09 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:15:22 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm("RobotomyRequestForm", 72, 45)
{
    *this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& e)
{
    if (this == &e)
        return (*this);
    this->_target = e._target;
    return (*this);
}

void RobotomyRequestForm::extra_message(Bureaucrat& b) const
{    
    if (b.getGrade() > this->get_gradeRequiredToExcecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->get_is_signed() == false)
		std::cout << "RobotomyRequestForm couldn't be executed by " << b.getName() << " because it wasn't signed!" << std::endl;
	else
	{
		std::srand(time(NULL));

		std::cout << "(Loud drill noises) " << std::endl;

		if (rand() % 2 == 0)
            std::cout << "[Information] " << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "[Information] " << _target << " robotomization failed" << std::endl;
	}
}
