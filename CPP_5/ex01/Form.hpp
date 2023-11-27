/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:08:26 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:12:55 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _is_signed;
        const int _gradeRequiredToSign;
        const int _gradeRequiredToExcecute;

    public:
        Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExcecute );
        ~Form();
        Form(const Form& cpy);
        Form &operator=(const Form& e);
        std::string getName();
        int get_is_signed();
        int get_gradeRequiredToSign();
        int get_gradeRequiredToExcecute();
        
        void beSigned(Bureaucrat& b);
    
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

std::ostream & operator<<( std::ostream & o, Form & b);

# endif
