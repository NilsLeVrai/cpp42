/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:01:41 by niabraha          #+#    #+#             */
/*   Updated: 2025/06/23 13:46:19 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"

class Bureaucrat;

class Form {

	public:
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return RED BOLD "Grade too high!" RESET;
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return RED BOLD "Grade too low!" RESET;
			}
		};

		Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		Form(const std::string _name, int _grade_to_sign, int _grade_to_exec);
		~Form();

		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat &bureaucrat);
	
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		void				signForm();
};