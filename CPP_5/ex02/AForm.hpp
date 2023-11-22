/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:08:26 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:13:38 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>
#include<fstream>
#include"Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _is_signed;
        const int _gradeRequiredToSign;
        const int _gradeRequiredToExcecute;

    public:
        AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExcecute );
        ~AForm();
        AForm(const AForm& cpy);
        AForm &operator=(const AForm& e);
        
        std::string getName() const;
        int get_is_signed() const;
        int get_gradeRequiredToSign() const;
        int get_gradeRequiredToExcecute() const;
        void beSigned(Bureaucrat& b);
        virtual void extra_message(Bureaucrat& b) const = 0;
        virtual void execute(Bureaucrat const & executor) const;

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

std::ostream & operator<<( std::ostream & o, AForm & b);

# endif
