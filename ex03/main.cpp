#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{	
    Intern 		someRandomIntern;

	std::cout << YELLOW "-----Intern creates forms-----" NC << std::endl;
	AForm*		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	AForm*		ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Handsome Jack");
	AForm*		scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Claptrap");

	std::cout << "         " << std::endl;

	std::cout << *rrf << std::endl;
	std::cout << *ppf << std::endl;
	std::cout << *scf << std::endl;

	delete rrf;
	delete ppf;
	delete scf;

	std::cout << "         " << std::endl;
	std::cout << YELLOW "-----Intern creates false form-----" NC << std::endl;
	try
	{
		someRandomIntern.makeForm("FalseName", "FalseTarget");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
