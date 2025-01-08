/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:42:12 by niabraha          #+#    #+#             */
/*   Updated: 2025/01/08 16:50:44 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harlFilter;
	std::string convertUpper;

	if (argc != 2) {
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./harlFilter Warning/Error/Info/Debug" << std::endl;
		return (0);
	}
	convertUpper = argv[1];
	for (std::string::size_type i = 0; i < convertUpper.size(); i++) {
		convertUpper[i] = std::toupper(static_cast<unsigned char>(convertUpper[i]));
	}
	harlFilter.complain(convertUpper);
	return (0);
}