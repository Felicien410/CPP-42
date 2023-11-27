/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feliciencatteau <feliciencatteau@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 07:17:34 by feliciencat       #+#    #+#             */
/*   Updated: 2023/10/03 08:36:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string out = filename + ".replace";
    std::ifstream inputFile(filename.c_str());


    if (s1.length() == 0)
    {
        std::cerr << "Error: s1 is null " << "\n";
        return 1;
    }
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return 1;
    }
    else
        replace_in_file(inputFile, s1, s2, out);
}
