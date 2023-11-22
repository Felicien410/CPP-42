/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:47:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:13:51 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

int main()
{
    std::cout << "[I] Create the Bureaucrat 'Christophe' and 'Stephane' and 'Dominique' with grade 150, 75 and 1" << std::endl;
    Bureaucrat christophe("Christophe", 150);
    Bureaucrat Stephane("Stephane", 75);
	Bureaucrat Dominique("Domi", 1);
	std::cout << std::endl;
	std::cout << std::endl;

    std::cout << "[II] creat 3 forms that herit from AForm: ShrubberyCreationForm, PresidentialPardonForm and RobotomyRequestForm" << std::endl;
	ShrubberyCreationForm Shruberry("Domi");
	PresidentialPardonForm President("Domi");
	RobotomyRequestForm Robot("Domi");
	std::cout << std::endl;

    std::cout << "[III] Execute the forms without sign them with Dominique" << std::endl;
	Dominique.executeForm(Shruberry);
    std::cout << "[III.2] Sign the forms and execute them" << std::endl;
	Shruberry.beSigned(Dominique);
	Dominique.executeForm(Shruberry);

	std::cout << std::endl;

	Dominique.executeForm(President);
	President.beSigned(Dominique);
	Dominique.executeForm(President);

	std::cout << std::endl;

	Dominique.executeForm(Robot);
	Robot.beSigned(Dominique);
	Dominique.executeForm(Robot);

    std::cout << "-------------------------------" << std::endl;
    std::cout << "[III] Execute the forms without sign them with Stephane" << std::endl;
    
    
	Stephane.executeForm(Shruberry);
    std::cout << "[III.2] Sign the forms and execute them" << std::endl;
	Shruberry.beSigned(Stephane);
	Stephane.executeForm(Shruberry);

	std::cout << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "[IV] Try to create a form with a grade out of bounds" << std::endl;
    try {
        Stephane.executeForm(President);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
	std::cout << std::endl;

	try {
		christophe.executeForm(Shruberry);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
    

	std::cout << std::endl;
	return 0;
    
}
