/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:37:15 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/21 08:15:29 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm("ShrubberyCreationForm", 145, 137)
{
    *this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& e)
{
    if (this == &e)
        return (*this);
    this->_target = e._target;
    return (*this);
}  

void ShrubberyCreationForm::extra_message(Bureaucrat& b) const
{
    if (b.getGrade() > get_gradeRequiredToExcecute())
        throw AForm::GradeTooLowException();
    else if (get_is_signed() == false)
        std::cout << "ShrubberyCreationForm couldn't be executed by " << b.getName() << " because it wasn't signed!" << std::endl;
    else
    {
        std::ofstream myfile;
        myfile.open((_target + "_shrubbery").c_str());
        myfile << "       _-_" << std::endl;
        myfile << "    /~~   ~~\\" << std::endl;
        myfile << " /~~         ~~\\" << std::endl;
        myfile << "{               }" << std::endl;
        myfile << " \\  _-     -_  /" << std::endl;
        myfile << "   ~  \\\\ //  ~" << std::endl;
        myfile << "_- -   | | _- _" << std::endl;
        myfile << "  _ -  | |   -_" << std::endl;
        myfile << "      // \\\\" << std::endl;
        myfile << "     //   \\\\" << std::endl;
        myfile << "    //     \\\\" << std::endl;
        myfile << "   //       \\\\" << std::endl;
        myfile << "  //         \\\\" << std::endl;
        myfile << " //           \\\\" << std::endl;
        myfile << "//             \\\\" << std::endl;
        myfile << "||             ||" << std::endl;
        myfile << "||             ||" << std::endl;
        myfile << "||             ||" << std::endl;
        myfile << "||             ||" << std::endl;
        myfile << "||_____________||" << std::endl;
        myfile << "|_______________|" << std::endl;
        myfile << " \\_____________/" << std::endl;
        myfile.close();
    }
}
