/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:14:21 by feliciencat       #+#    #+#             */
/*   Updated: 2023/11/27 17:17:00 by feliciencat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include<iostream>
#include<string.h>
#include<algorithm>

class EasyFindException : public std::exception {
	public:
		const char *what() const throw() {
			return "easyfind: exception: element not found within container";
   		}
};

template<typename T>
bool easyfind(T& container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) == container.end())
	{
		throw EasyFindException();
		return false;
	}
	else
		return true;
}

#endif