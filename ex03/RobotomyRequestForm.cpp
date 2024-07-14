#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &toCopy) : AForm(toCopy), target(toCopy.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &toCopy)
{
	if (this != &toCopy)
	{
        AForm::operator=(toCopy); 
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	
	std::cout << CYAN << "*bzzzbzzzbzzzzzzz*" << NC << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << GREEN << target << " has been robotomized successfully" << NC << std::endl;
	else
		std::cout << RED << target << " robotomization failed" << NC << std::endl;
}
