#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << YELLOW << "-----Test invalid Form-----" << NC << std::endl;
	try
	{
		Form	Form3("Form1", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form	Form3("Form2", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << YELLOW << "-----Test sign Form-----" << NC << std::endl;
	Bureaucrat	HandsomeJack("Handsome Jack Boss", 1);
	Bureaucrat	Rhys("Rhys employee", 150);
	Form 		Hyperion("Butt stallion adoption paper", 1, 1);

	std::cout << HandsomeJack << std::endl;
	std::cout << Rhys << std::endl;
	std::cout << Hyperion << std::endl;

	std::cout << YELLOW << "-----Invalid Signed-----" << NC << std::endl;
	try
	{
		Hyperion.beSigned(Rhys);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Rhys.signForm(Hyperion);

	std::cout << YELLOW << "-----Valid Signed-----" << NC << std::endl;
	HandsomeJack.signForm(Hyperion);
	std::cout << Hyperion << std::endl;

	return 0;
}
