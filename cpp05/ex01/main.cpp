/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:31:11 by niabraha          #+#    #+#             */
/*   Updated: 2025/06/23 17:06:22 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		std::cout << WHITE BOLD "Basic tests\n";
		Form form("impots.gouv", 5, 50);
		
		std::cout << form.getName() << CYAN BOLD << ", form has grade to sign " << GREEN BOLD << form.getGradeToSign() << RESET << std::endl;
		std::cout << form.getName() << CYAN BOLD << ", form has grade to execute " << GREEN BOLD << form.getGradeToExec() << RESET << std::endl;
		std::cout << form.getName() << CYAN BOLD << ", form is " << (form.getIsSigned() ? GREEN BOLD "signed" : RED BOLD "not signed") << RESET << std::endl;
		Bureaucrat bureaucrat("niabraha", 50);
		std::cout << bureaucrat.getName() << CYAN BOLD << ", bureaucrat has grade " << GREEN BOLD << bureaucrat.getGrade() << RESET << std::endl;
		form.beSigned(bureaucrat);
		std::cout << form.getName() << CYAN BOLD << ", form is " << (form.getIsSigned() ? GREEN BOLD "signed" : RED BOLD "not signed") << RESET << std::endl;
	}
	catch (const std::exception &error) {
		std::cerr << YELLOW BOLD << "Exception caught: " << RESET << error.what() << '\n';
	}
}