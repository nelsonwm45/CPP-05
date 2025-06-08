#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	exception_bureaucrat()
{
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

void	exception_form()
{
	// Too Low
	try
	{
		Form("Divorce", 151, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try
	{
		Form("Divorce", 50, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	try
	{
		Form("Divorce", 151, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}


	// Too High
	try
	{
		Form("Suicide", 0, 75);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		Form("Suicide", 75, -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		Form("Suicide", -1, -1);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

void	exception_class()
{
	std::cout << YELLOW << "# Exception Class" << RESET << std::endl << "\n";

	exception_bureaucrat();
	exception_form();
}

void	bureaucrat_ocf()
{
	Bureaucrat	b1("Bamboo", 10); // Constructor
	Bureaucrat	b2(b1); // Copy Constructor
	Bureaucrat	b3("Unknown", 30);

	b3 = b1; // Copy assignment test, but i think seems useless?
	std::cout << b1;
	std::cout << "\n";
}

void	form_ocf()
{
	Form	f1("Agreement", 50, 50);
	Form	f2(f1);
	Form	f3("Question", 20, 20);

	f3 = f1;
	std::cout << f1 << std::endl;
}

void	ocf_test()
{
	std::cout << YELLOW << "# Ocf Test" << RESET << std::endl << "\n";
	
	bureaucrat_ocf();
	form_ocf();
}

void	form_beSigned_test()
{
	std::cout << YELLOW << "# Form::beSigned Test" << RESET << std::endl << "\n";

	// Bureaucrat can't sign cus too low grade
	Bureaucrat	b1("Alpha", 50);
	Form		f1("A", 45, 45);

	b1.signForm(f1);

	// Bureaucrat can sign
	Bureaucrat	b2("Beta", 40);

	b2.signForm(f1);
	b2.signForm(f1); // Double sign
}

int main()
{
	ocf_test();
	exception_class();
	increase_grade();
	decrease_grade();
	form_beSigned_test();
	return 0;
}
