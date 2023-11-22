/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:47:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 10:41:29 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include"Form.hpp"

int main()
{  
    std::cout << std::endl;
    std::cout << "[I] Want to creat Bureaucrat 'Herve' qnd a Form 'Formulaire'";
    std::cout << ", then i want to downgrade Herve and urprade him until can't level up"  << std::endl << std::endl;

    try
    {
        Bureaucrat a("Herve", 1);
        Form Formulaire("Document immigration", 1, 13 );
        std::cout << a;
        std::cout << Formulaire;
        a.decrement_grade();
        std::cout << a;
        a.increment_grade();
        std::cout << a;
        a.increment_grade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[II] Creat Form grade is out of bounds: "<< std::endl << std::endl;
    try
    {
        Form Formulaire2("Document immigration 1", 0, 13 );
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[III] Creat Form and signe it 2x: "<< std::endl << std::endl;
    try
    {
        Bureaucrat b("Bruno", 1);
        Form Formulair3("Document CAF", 13, 13 );
        std::cout << Formulair3;
        Formulair3.beSigned(b);
        Formulair3.beSigned(b);
        std::cout << Formulair3;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[IV] Creat Form and signe it with no autorisation : "<< std::endl << std::endl;
    try
    {
        Bureaucrat c("Cristophe", 50);
        Form Formulair4("Document Patrimoine immobilier", 13, 13 );
        std::cout << Formulair4;
        Formulair4.beSigned(c);
        std::cout << Formulair4;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "[V] be signed / sign form : "<< std::endl << std::endl;
    try
    {
        Bureaucrat d("Dominique", 12);
        Form Formulair5("Document cessez le feu", 13, 13);
        std::cout << Formulair5;
        d.signForm("salut", 0);
        std::cout << Formulair5;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
}
