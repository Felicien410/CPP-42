/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:45:31 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:15:09 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include"AForm.hpp"
#include"Bureaucrat.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& cpy);
        Intern &operator=(const Intern& e);
        
        AForm *makeForm(std::string name, std::string target);
};

#endif
