#include "Bureaucrat.hpp"

int main()
{
	std::cout << YELLOW << "-----Test GradeTooHigh-----" << NC << std::endl;
	try 
	{
		Bureaucrat Aurel(0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << YELLOW << "-----Test GradeTooLow-----" << NC << std::endl;
	try 
	{
		Bureaucrat Aurel(151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "-----Test incrementGrade-----" << NC << std::endl;
	Bureaucrat Aurel("Aurel", 150);
	Aurel.printGrade();
	Aurel.incrementGrade(10);
	std::cout << CYAN << "Incremented 10" << NC << std::endl;
	Aurel.printGrade();
	std::cout << YELLOW << "-----Test decrementGrade-----" << NC << std::endl;
	Aurel.printGrade();
	Aurel.decrementGrade(10);
	std::cout << CYAN << "Decremented 10" << NC << std::endl;
	Aurel.printGrade();

	std::cout << YELLOW << "-----Test decrement too low-----" << NC << std::endl;
	try 
	{
		Aurel.decrementGrade(10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Aurel.printGrade();
	std::cout << YELLOW << "-----Test increment too high-----" << NC << std::endl;
	try 
	{
		Aurel.incrementGrade(150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Aurel.printGrade();

	return 0;
}
