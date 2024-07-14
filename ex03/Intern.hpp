#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(Intern const &toCopy);
		Intern &operator=(Intern const &toCopy);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
