#pragma once

#include <iostream>
#include <exception>

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

class Bureaucrat {

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

	Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();
	
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);