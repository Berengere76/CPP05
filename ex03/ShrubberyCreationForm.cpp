#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &toCopy) : AForm(toCopy), target(toCopy.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &toCopy)
{
	if (this != &toCopy)
	{
        AForm::operator=(toCopy); 
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return RED "File not open" NC;
}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	if (!isSigned)
		throw FormNotSignedException();
	
	std::ofstream file;
	std::string filename = target + "_shrubbery";

	file.open(filename.c_str(), std::ios::out);
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenException();

	std::cout << GREEN << "Creating file " << filename << NC << std::endl;

	file << "_________________________________________" << std::endl;
	file << "___________ ¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "____________ ¶¶¶¶¶¶¶____¶¶¶ " << std::endl;
	file << "_____________ ¶¶¶¶¶__¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "______¶¶¶¶¶___ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << std::endl;
	file << "___ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶______¶¶¶ " << std::endl;
	file << "_ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__________¶ " << std::endl;
	file << "¶¶¶_______ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "_______ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "_____¶¶¶¶¶¶¶¶¶__ ¶¶¶____¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "____¶¶¶¶¶¶¶_____ ¶¶¶¶______¶¶¶¶¶¶ " << std::endl;
	file << "____¶¶¶¶¶_______ ¶¶¶¶_______¶¶¶¶¶ " << std::endl;
	file << "____¶¶¶¶_________ ¶¶¶¶______¶¶¶¶¶ " << std::endl;
	file << "____¶¶¶__________ ¶¶¶¶_______¶¶¶¶ " << std::endl;
	file << "____¶¶____________ ¶¶¶¶______¶¶¶ " << std::endl;
	file << "____¶¶____________ ¶¶_¶_______¶¶ " << std::endl;
	file << "____¶_____________ ¶¶¶¶¶______¶ " << std::endl;
	file << "___________________ ¶¶¶¶ " << std::endl;
	file << "___________________ ¶¶_¶ "  << std::endl;
	file << "___________________ ¶¶¶¶¶ " << std::endl;
	file << "___________________ ¶¶¶¶¶ " << std::endl;
	file << "____________________ ¶¶_¶ " << std::endl;
	file << "____________________ ¶¶¶¶¶____¶ " << std::endl;
	file << "_________________ ¶__¶¶¶¶¶__¶¶ " << std::endl;
	file << "_________________ ¶¶¶¶¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "__________________ ¶¶¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "___________________________________________ " << std::endl;
	file << "_____________________¶¶ " << std::endl;
	file << "_____________________¶¶ " << std::endl;
	file << "____________________¶¶¶¶ " << std::endl;
	file << "____________________¶__¶ " << std::endl;
	file << "___________________¶___¶¶ " << std::endl;
	file << "__________________¶¶____¶¶ " << std::endl;
	file << "_________________¶¶______¶ " << std::endl;
	file << "________________¶¶¶¶_____¶¶ " << std::endl;
	file << "________________¶_¶_¶¶__¶_¶¶ " << std::endl;
	file << "__________________¶¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "_________________¶¶¶__¶¶¶__¶¶ " << std::endl;
	file << "_______________¶¶¶_____¶¶___¶¶ " << std::endl;
	file << "______________¶¶_____________¶¶ " << std::endl;
	file << "_____________¶¶_______________¶¶ " << std::endl;
	file << "___________¶¶¶_______________¶¶¶¶ " << std::endl;
	file << "_____________¶¶¶¶¶___________¶¶ " << std::endl;
	file << "______________¶¶¶_¶¶¶_¶¶_¶¶¶__¶¶ " << std::endl;
	file << "____________¶¶_¶¶¶¶_¶¶¶¶_¶¶¶¶¶¶¶¶ " << std::endl;
	file << "__________¶¶¶__¶¶¶___¶¶_¶¶¶__¶¶_¶¶¶ " << std::endl;
	file << "___________¶_________¶¶__¶¶_______¶¶ " << std::endl;
	file << "________¶¶¶________________________¶¶¶ " << std::endl;
	file << "_________¶¶¶¶__________________¶___¶¶¶ " << std::endl;
	file << "___________¶¶__________________¶¶¶¶¶ " << std::endl;
	file << "__________¶¶__¶______¶___¶__¶¶__¶¶¶¶ " << std::endl;
	file << "_________¶¶_¶¶¶¶____¶¶¶__¶¶_¶¶¶¶¶¶_¶¶ " << std::endl;
	file << "__________¶¶¶_¶____¶¶¶¶__¶¶¶¶__¶¶¶__¶¶ " << std::endl;
	file << "__________¶¶_¶¶_¶¶¶¶__¶_¶¶_¶¶____¶___¶¶¶ " << std::endl;
	file << "________¶¶¶__¶¶¶¶¶___¶¶¶¶__¶___________¶¶¶ " << std::endl;
	file << "_____¶¶¶¶_____________¶¶_________________¶¶¶ " << std::endl;
	file << "____¶¶¶¶¶¶¶_______________________________¶¶¶¶¶ " << std::endl;
	file << "__________¶_____________________¶¶__¶¶¶¶¶¶¶ " << std::endl;
	file << "_________¶¶__________________¶¶_¶¶¶¶¶¶__¶¶ " << std::endl;
	file << "________¶¶___________________¶¶¶¶¶__¶¶___¶¶ " << std::endl;
	file << "______¶¶¶__¶¶¶_____¶__¶__¶¶¶_¶¶_¶¶¶_______¶¶ " << std::endl;
	file << "____¶¶¶¶¶¶¶¶¶¶____¶¶__¶¶_¶¶¶_¶¶__¶¶________¶¶¶ " << std::endl;
	file << "______¶¶¶___¶¶__¶¶¶¶_¶¶¶_¶__¶¶¶______________¶¶¶ " << std::endl;
	file << "_____¶¶____¶¶_¶¶¶_¶¶¶__¶¶¶__¶¶_____________¶¶¶¶¶¶" << std::endl;
	file << "____¶¶_____¶¶¶¶¶__¶¶___¶¶__________________¶¶ " << std::endl;
	file << "_¶¶¶¶¶¶¶____________________________________¶ " << std::endl;
	file << "___¶_¶_¶¶¶___________________________________¶¶ " << std::endl;
	file << "_______¶¶______________________________¶¶¶¶¶¶¶¶¶¶" << std::endl;
	file << "______¶¶____¶¶________________¶____¶¶¶__¶¶__¶ " << std::endl;
	file << "___¶¶¶¶¶¶¶¶¶¶¶___________¶¶___¶¶¶___¶¶¶¶¶¶¶ " << std::endl;
	file << "______¶¶¶¶___¶__¶¶¶¶__¶¶_¶¶¶__¶¶¶¶¶¶¶¶ " << std::endl;
	file << "___________¶¶¶¶¶¶_¶¶_¶¶¶¶¶¶¶¶¶¶____¶¶¶¶ " << std::endl;
	file << "___________¶¶¶¶___¶¶¶¶¶¶¶¶¶¶¶_¶¶ " << std::endl;
	file << "____________________¶¶¶¶¶¶¶¶¶ " << std::endl;
	file << "____________________¶¶¶¶¶¶¶ " << std::endl;
	file << "____________________¶¶¶¶¶ " << std::endl;
	file << "____________________________________________ " << std::endl;

	file.close();
}
