/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:34:19 by feliciencat       #+#    #+#             */
/*   Updated: 2023/09/26 09:00:27 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#ifndef REPLACE_HPP
# define REPLACE_HPP

void replace_in_file(std::ifstream& inputFile, std::string &s1, std::string &s2, std::string out);

#endif 