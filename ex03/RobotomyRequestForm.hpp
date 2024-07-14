#pragma once

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string const target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &toCopy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &toCopy);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;

};
