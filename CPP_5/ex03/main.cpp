/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:47:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:15:12 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"Intern.hpp"

int main()
{
	AForm *form_robot;
	AForm *form_president;
	AForm *form_shrubbery;
	Intern intern;

	form_robot = intern.makeForm("robotomy request", "Bender");
	form_president = intern.makeForm("presidential pardon", "Bender");
	form_shrubbery = intern.makeForm("shrubbery creation", "Bender");
	
	intern.makeForm("not_exist", "Bender");
	std::cout << std::endl;
	std::cout << std::endl;
	
	delete form_robot;
	delete form_president;
	delete form_shrubbery;
	return (0);
}
