/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:08:26 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:12:46 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>
#include"Form.hpp"

class Bureaucrat
{
    
    private:
        std::string _name;
        int _grade;
    
    public:
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& cpy);
        Bureaucrat &operator=(const Bureaucrat& e);
        std::string getName();
        int getGrade(); 
        void decrement_grade();
        void increment_grade();
        void signForm(std::string form_name, bool was_signed);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade to high");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Grade to low");
                }
        };
};

std::ostream & operator<<( std::ostream & o, Bureaucrat & b);

#endif

