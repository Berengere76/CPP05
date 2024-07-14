#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const name;
		bool isSigned;
		int const gradeToSign;
		int const gradeToExecute;

	public:
		Form();
		Form(Form const &toCopy);
		Form &operator=(Form const &toCopy);
		~Form();

		Form(std::string name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, Form const &form);
