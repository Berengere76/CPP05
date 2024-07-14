#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &toCopy)
{
	(void)toCopy;
}

Intern &Intern::operator=(Intern const &toCopy)
{
	(void)toCopy;
	return *this;
}

Intern::~Intern()
{
}

static AForm *createShrubberyCreationForm(std::string const &target)
{
	std::cout << PURPLE << "Intern creates ShrubberyCreationForm" << NC << std::endl;
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequestForm(std::string const &target)
{
	std::cout << PURPLE << "Intern creates RobotomyRequestForm" << NC << std::endl;
	return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(std::string const &target)
{
	std::cout << PURPLE << "Intern creates PresidentialPardonForm" << NC << std::endl;
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	AForm *(*formCreators[3])(std::string const &target) = {&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentialPardonForm};
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
			return formCreators[i](target);
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return RED "Form not found" NC;
}
