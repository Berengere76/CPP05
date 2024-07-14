#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const target;
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &toCopy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &toCopy);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;

		class FileNotOpenException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
