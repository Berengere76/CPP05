#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{	
	std::cout << YELLOW << "-----Create company-----" << NC << std::endl;
	Bureaucrat	HandsomeJack("Handsome Jack Boss", 1);
	Bureaucrat	Rhys("Rhys employee", 135);
	Bureaucrat	Claptrap("Claptrap", 40);
	Bureaucrat	Scooter("Scooter", 70);

	std::cout << HandsomeJack << std::endl;
	std::cout << Rhys << std::endl;
	std::cout << Claptrap << std::endl;
	std::cout << Scooter << std::endl;

	std::cout << YELLOW << "-----Create forms-----" << NC << std::endl;
	PresidentialPardonForm	PPF("Handsome Jack");
	RobotomyRequestForm		RRF("Rhys");
	ShrubberyCreationForm	SCF("Claptrap");

	std::cout << PPF << std::endl;
	std::cout << RRF << std::endl;
	std::cout << SCF << std::endl;

	std::cout << YELLOW << "-----Sign forms-----" << NC << std::endl;
	Rhys.signForm(PPF);
	Claptrap.signForm(RRF);
	Scooter.signForm(SCF);
	HandsomeJack.signForm(PPF);
	HandsomeJack.signForm(RRF);
	HandsomeJack.signForm(SCF);
	std::cout << "                       " << std::endl;
	std::cout << PPF << std::endl;
	std::cout << RRF << std::endl;
	std::cout << SCF << std::endl;

	std::cout << YELLOW << "-----Execute forms-----" << NC << std::endl;

	std::cout << "                       " << std::endl;
	std::cout << CYAN << "***Rhys try to execute PPF***" << NC << std::endl;
	Rhys.executeForm(PPF);
	std::cout << "                       " << std::endl;
	std::cout << CYAN << "***HandsomeJack execute PPF***" << std::endl;
	HandsomeJack.executeForm(PPF);
	std::cout << "                       " << std::endl;
	std::cout << CYAN << "***HandsomeJack execute RRF***" << std::endl;
	HandsomeJack.executeForm(RRF);
	std::cout << "                       " << std::endl;
	std::cout << CYAN << "***HandsomeJack execute SCF***" << std::endl;
	HandsomeJack.executeForm(SCF);

	return 0;
}
