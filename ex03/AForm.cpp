#include "AForm.hpp"

AForm::AForm() : name("AForm"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(AForm const &toCopy) : name(toCopy.name), isSigned(toCopy.isSigned), gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute)
{
}

AForm &AForm::operator=(AForm const &toCopy)
{
	if (this != &toCopy)
	{
		isSigned = toCopy.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	if (isSigned)
	{
		throw AForm::AlreadySignedException();
	}
	isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" NC;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" NC;
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return RED "Form is not signed" NC;
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return RED "Form is already signed" NC;
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << CYAN << "Form " << form.getName() << " is " << NC;
	if (!form.getIsSigned())
	{
		out << RED << "not signed" << NC << std::endl;
		out << YELLOW << "Need grade " << form.getGradeToSign() << " to be signed and grade " << form.getGradeToExecute() << " to be executed" << NC << std::endl;
	}
	else
		out << GREEN <<  "signed" << NC << std::endl;
	return out;
}
