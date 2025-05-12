/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:24:17 by niabraha          #+#    #+#             */
/*   Updated: 2025/05/12 17:04:15 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>

class Bureaucrat {

	public:
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too highhhhh";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too lowwwwww";
			}
		};

		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat &operator=(const Bureaucrat &src);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
	
	private:
		const std::string _name;
		int _grade;
};
