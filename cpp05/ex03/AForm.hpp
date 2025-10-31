#pragma once

# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(const Bureaucrat &bureaucrat);

		virtual void		execute(Bureaucrat const &executor) const = 0; // Pure virtual function

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form is already signed";
				}
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);