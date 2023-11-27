/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:03:37 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/03 08:36:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"replace.hpp"

void replace_in_file(std::ifstream& inputFile, std::string &s1, std::string &s2, std::string out)
{
    std::string file;
    char car;
    
    while(inputFile.get(car))
        file += car;

    size_t pos = file.find(s1);
    while (pos != std::string::npos)
    {
        file.erase(pos, s1.length());
        file.insert(pos, s2);
        pos = file.find(s1, pos + s2.length());
    }
    std::ofstream outFile(out.c_str());
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open or create ./filename.replace for writing." << std::endl;
        return;
    }
    outFile << file << std::endl;
    outFile.close();
}
