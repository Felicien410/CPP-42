/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:47:01 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/22 21:28:28 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Herve", 1);
        std::cout << a;
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
}