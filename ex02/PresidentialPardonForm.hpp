#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string const target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &toCopy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &toCopy);
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;
};
