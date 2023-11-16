/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:34:47 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/16 16:25:12 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string>
#include <stack>

class RNP
{
    public :
        RNP(std::string argv);
        RNP(RNP const & src);
        ~RNP();
        RNP & operator=(RNP const & rhs);

        int verifNumbers(std::string args);
        void addStack();

    private:
        std::stack<int> stockage;
        std::string _argv;
};

#endif