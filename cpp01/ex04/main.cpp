/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:54:33 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 18:21:31 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

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
}