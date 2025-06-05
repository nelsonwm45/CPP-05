#include "Bureaucrat.hpp"

void	decrease_grade()
{
	std::cout << YELLOW << "# Decrease Grade" << RESET << std::endl << "\n";
	Bureaucrat b1("Moon", 34);

	std::cout << BLUE << "----------Initial Value----------" << RESET << std::endl;
	std::cout << b1 << std::endl;
	std::cout << BLUE << "----------Adjusted Value----------" << RESET << std::endl;
	b1.downGrade();
	std::cout << b1 << std::endl;
}

void	increase_grade()
{
	std::cout << YELLOW << "# Increase Grade" << RESET << std::endl << "\n";
	Bureaucrat b1("Sun", 10);

	std::cout << BLUE << "----------Initial Value----------" << RESET << std::endl;
	std::cout << b1 << std::endl;
	std::cout << BLUE << "----------Adjusted Value----------" << RESET << std::endl;
	b1.upGrade();
	std::cout << b1 << std::endl;
}

void	exception_class()
{
	std::cout << YELLOW << "# Exception Class" << RESET << std::endl << "\n";
	// Too high
	try
	{
		Bureaucrat b1("Bamboo", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	
	// Too low
	try
	{
		Bureaucrat b2("Panda", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	
	// Grade 150
	try
	{
		Bureaucrat b3("Wonda", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	// Grade 1
	try
	{
		Bureaucrat b4("Seel", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void	ocf_test()
{
	std::cout << YELLOW << "# Ocf Test" << RESET << std::endl << "\n";
	
	Bureaucrat	b1("Bamboo", 10); // Constructor
	Bureaucrat	b2(b1); // Copy Constructor
	Bureaucrat	b3("Unknown", 30);

	b3 = b1; // Copy assignment test, but i think seems useless?
}

int main()
{
	ocf_test();
	exception_class();
	increase_grade();
	decrease_grade();
	return 0;
}
