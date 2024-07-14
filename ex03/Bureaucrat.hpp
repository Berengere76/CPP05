#pragma once

#include <iostream>
#include "colors.h"
#include "AForm.hpp"

# define MIN_GRADE 150
# define MAX_GRADE 1

class AForm;

class Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &toCopy);
		Bureaucrat &operator=(Bureaucrat const &toCopy);
		~Bureaucrat();

		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(std::string const &name);
		Bureaucrat(int grade);

		std::string const &getName() const;
		int getGrade() const;

		void printGrade() const;

		void incrementGrade(int i = 1);
		void decrementGrade(int i = 1);

		void signForm(AForm &form);
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
