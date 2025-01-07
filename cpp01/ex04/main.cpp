/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:54:33 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/07 17:58:00 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace(std::string filename, std::string s1, std::string s2)
{
    std::ofstream outfile;
    std::string::size_type pos;

    outfile.open((filename + ".replace").c_str());
    for (std::string::size_type i = 0; i < filename.length(); i++) {
        pos = filename.find(s1, i);
        if (pos != std::string::npos) {
            outfile << filename.substr(i, pos - i) << s2;
            i = pos + s1.length() - 1;
        } else {
            outfile << filename[i];
        }
    }
    outfile.close();
}

bool validateArguments(int argc, char **argv)
{
	std::ifstream file(argv[1]);
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cerr << "Usage: ./sed filename s1 s2" << std::endl;
		return (1);
	}
	if (!file)
	{
		std::cerr << "Couldn't open file." << std::endl;
		std::cerr << "Either bad permissions or file does not exist." << std::endl;
		return (1);
	}
	if (std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cerr << "Empty string are not allowed." << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv) 
{
	if (validateArguments(argc, argv))
	{
		std::cout << "Arguments are not valid." << std::endl;
		return (1);
	}
	std::cout << "File opened successfully." << std::endl;
	replace(argv[1], argv[2], argv[3]);
	return (0);
}