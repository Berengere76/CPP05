#include "Form.hpp"

Form::Form() : name("Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(Form const &toCopy) : name(toCopy.name), isSigned(toCopy.isSigned), gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute)
{
}

Form &Form::operator=(Form const &toCopy)
{
	if (this != &toCopy)
	{
		isSigned = toCopy.isSigned;
	}
	return *this;
}

Form::~Form()
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return RED "Grade is too high" NC;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return RED "Grade is too low" NC;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
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
