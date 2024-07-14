#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat () : name("default"), grade(150)
{

}

Bureaucrat::Bureaucrat (Bureaucrat const &toCopy) : name(toCopy.getName()), grade(toCopy.getGrade())
{

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &toCopy)
{
	if (this != &toCopy)
	{
		this->grade = toCopy.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat ()
{

}

Bureaucrat::Bureaucrat (std::string const &name, int grade) : name(name)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat (std::string const &name) : name(name), grade(150)
{

}

Bureaucrat::Bureaucrat (int grade) : name("default")
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	this->grade = grade;
}

std::string const &Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(int i)
{
	if (this->grade - i < MAX_GRADE)
		throw GradeTooHighException();
	this->grade -= i;
}

void Bureaucrat::decrementGrade(int i)
{
	if (this->grade + i > MIN_GRADE)
		throw GradeTooLowException();
	this->grade += i;
}

void Bureaucrat::printGrade () const
{
	std::cout << this->name << " grade: " << this->grade << std::endl;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << GREEN << this->name << " signs " << form.getName() << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->name << " couldn't sign " << form.getName() << " because " << e.what() << NC << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << this->name << " executed " << form.getName() << NC << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << this->name << " couldn't execute " << form.getName() << " because " << e.what() << NC << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what () const throw()
{
	return (RED "Grade is too high" NC);
}

const char *Bureaucrat::GradeTooLowException::what () const throw()
{
	return (RED "Grade is too low" NC);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << CYAN << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade() << NC << std::endl;
	return (out);
}
