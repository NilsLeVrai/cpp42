/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:54:33 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/06 18:09:59 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) 
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
}