#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 72, 45), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &toCopy) : AForm(toCopy), target(toCopy.target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &toCopy)
{
	if (this != &toCopy)
	{
        AForm::operator=(toCopy); 
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	std::cout << PURPLE << target << " has been pardoned by Zafod Beeblebrox." << NC << std::endl;
}