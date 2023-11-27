/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:48:53 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:15:06 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Intern.hpp"

#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed" << std::endl;
}

Intern::Intern(const Intern& cpy)
{
    *this = cpy;
}

Intern &Intern::operator=(const Intern& e)
{
    if (this == &e)
        return (*this);
    return (*this);
}

AForm *newPresidential(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *newRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *newShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *choosen_form = NULL;

    const std::string form_names[] = {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };

    AForm *(*FormConstructorPtr[])(std::string) = {
        newRobotomy,
        newPresidential,
        newShrubbery
    };

    for (size_t i = 0; i < 3; i += 1)
    {
        if (name == form_names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            choosen_form = FormConstructorPtr[i](target);;
            break ;
        }
    }
    if (!choosen_form)
        std::cerr << "Intern couldn't create " << name << " form" << std::endl;
    return choosen_form;
}
