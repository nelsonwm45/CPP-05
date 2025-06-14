#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void	decrease_grade()
{
	std::cout << "\n";
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
	std::cout << "\n";
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
	std::cout << "\n";
	// Too high
	try
	{
		Bureaucrat b1("Bamboo", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	// Too low
	try
	{
		Bureaucrat b2("Panda", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	// Grade 150
	try
	{
		Bureaucrat b3("Wonda", 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	// Grade 1
	try
	{
		Bureaucrat b4("Seel", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

// void	exception_form()
// {
// 	std::cout << "\n";
// 	// Too Low
// 	try
// 	{
// 		AForm("Divorce", 151, 50);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}

// 	try
// 	{
// 		AForm("Divorce", 50, 151);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}

// 	try
// 	{
// 		AForm("Divorce", 151, 151);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}


// 	std::cout << "\n";
// 	// Too High
// 	try
// 	{
// 		AForm("Suicide", 0, 75);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// 	try
// 	{
// 		AForm("Suicide", 75, -1);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// 	try
// 	{
// 		AForm("Suicide", -1, -1);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// }

void	exception_shrubbery()
{
	std::cout << "\n";
	ShrubberyCreationForm	s1("KL");
	Bureaucrat	b1("Salmon", 138);
	Bureaucrat	temp("Catfish", 1);

	// Attempt execute without signning
	b1.executeForm(s1);
	temp.executeForm(s1);

	// Sign and execute
	b1.signForm(s1);
	b1.executeForm(s1); // shud fail cus not enough grade

	Bureaucrat	b2("Magic", 120);
	b2.executeForm(s1);
}

void	exception_presidential()
{
	std::cout << "\n";
	PresidentialPardonForm	p1("Innocent");
	Bureaucrat	b1("Hakim", 23);
	Bureaucrat	temp("Catfish", 1);

	// Attempt execute without signning
	b1.executeForm(p1);
	temp.executeForm(p1);

	// Sign and execute
	b1.signForm(p1);
	b1.executeForm(p1); // shud fail cus not enough grade

	Bureaucrat	b2("Magic", 5);
	b2.executeForm(p1);
}

void	exception_robotomy()
{
	std::cout << "\n";
	RobotomyRequestForm	r1("Chainsaw");
	Bureaucrat	b1("Ketchup", 64);
	Bureaucrat	temp("Catfish", 1);

	// Attempt execute without signning
	b1.executeForm(r1);
	temp.executeForm(r1);

	// Sign and execute
	b1.signForm(r1);
	b1.executeForm(r1); // shud fail cus not enough grade

	Bureaucrat	b2("Magic", 30);
	b2.executeForm(r1); // shud pass but pass robot
	b2.executeForm(r1); // shud pass and fail robot
	b2.executeForm(r1); // shud pass but pass robot
	b2.executeForm(r1); // shud pass and fail robot
}

void	exception_class()
{
	std::cout << "\n";
	std::cout << YELLOW << "# Exception Class" << RESET << std::endl << "\n";

	exception_bureaucrat();
	// exception_form();
	std::cout << "\nIMPORTANT EX02\n";
	exception_shrubbery();
	exception_presidential();
	exception_robotomy();
}

void	bureaucrat_ocf()
{
	std::cout << "\n";
	Bureaucrat	b1("Bamboo", 10); // Constructor
	Bureaucrat	b2(b1); // Copy Constructor
	Bureaucrat	b3("Unknown", 30);
	Bureaucrat	b4;

	b3 = b1; // Copy assignment test, but i think seems useless?
	std::cout << b3;
	std::cout << "\n";
}

// void	form_ocf()
// {
// 	std::cout << "\n";
// 	AForm	f1("Agreement", 50, 50);
// 	AForm	f2(f1);
// 	AForm	f3("Question", 20, 20);

// 	f3 = f1;
// 	std::cout << f3 << std::endl;
// }

void	shrubbery_ocf()
{
	std::cout << "\n";
	ShrubberyCreationForm	s1("KL");
	ShrubberyCreationForm	s2(s1);
	ShrubberyCreationForm	s3("Sarawak");

	s3 = s1;
	std::cout << s3 << std::endl;
}

void	presidential_ocf()
{
	std::cout << "\n";
	PresidentialPardonForm	p1("Donald");
	PresidentialPardonForm	p2(p1);
	PresidentialPardonForm	p3("Ducklings");

	p3 = p1;
	std::cout << p3 << std::endl;
}

void	robotomy_ocf()
{
	std::cout << "\n";
	RobotomyRequestForm	r1("Gurenragan");
	RobotomyRequestForm	r2(r1);
	RobotomyRequestForm	r3("SeedGundam");

	r3 = r1;
	std::cout << r3 << std::endl;
}

void	intern_ocf()
{
	std::cout << "\n";
	Intern	i1;
	Intern	i2(i1);
}

void	ocf_test()
{
	std::cout << "\n";
	std::cout << YELLOW << "# Ocf Test" << RESET << std::endl << "\n";
	
	bureaucrat_ocf();
	// form_ocf();  // abstract class cannot instantiate
	std::cout << "\nImportant_EX02\n";
	shrubbery_ocf();
	presidential_ocf();
	robotomy_ocf();
	std::cout << RED << "\n IMPORTANT: EX03 \n" << RESET;
	intern_ocf();
}

/*
	 delete on a pointer is safe even if the pointer is nullptr.
*/
void	intern_makeformtest()
{
	std::cout << RED << "\n IMPORTANT: EX03 \n" << RESET;
	std::cout << "\n" << YELLOW << "# Intern Make Form Test" << RESET << "\n\n";
	Intern i1;
	AForm *s1 = NULL, *s2 = NULL, *p1 = NULL, *p2 = NULL, *r1 = NULL, *r2 = NULL;

	try { s1 = i1.makeForm("ShrubberyCreationForm", "Christmas"); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n\n";

	try { s2 = i1.makeForm("ShrubbberyCreationForm", "Selangor"); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n\n";

	try { p1 = i1.makeForm("PresidentialPardonForm", "Innocent"); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n\n";

	try { p2 = i1.makeForm("Presidential Pardon Form", "Cruelty"); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n\n";

	try { r1 = i1.makeForm("RobotomyRequestForm", "Gundam"); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n\n";

	try { r2 = i1.makeForm("ROBOTOMYREQUESTFORM", "FallenAngel"); }
	catch (const std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n\n";

	Bureaucrat b1("Tencent", 1);

	if (s1) { b1.signForm(*s1); b1.executeForm(*s1); }
	else { std::cout << "I'm not doing anything\n";}
	std::cout << "\n\n";

	if (s2) { b1.signForm(*s2); }
	else { std::cout << "I'm not doing anything\n";}
	std::cout << "\n\n";

	if (p1) { b1.signForm(*p1); }
	else { std::cout << "I'm not doing anything\n";}
	std::cout << "\n\n";

	if (p1) { b1.executeForm(*p1); }
	else { std::cout << "I'm not doing anything\n";}
	std::cout << "\n\n";

	if (r1) { b1.executeForm(*r1); b1.signForm(*r1); b1.executeForm(*r1); }
	else { std::cout << "I'm not doing anything\n";}
	std::cout << "\n\n";

	if (r2) { b1.signForm(*r2); }
	else { std::cout << "I'm not doing anything\n";}
	std::cout << "\n\n";

	delete s1;
	delete s2;
	delete p1;
	delete p2;
	delete r1;
	delete r2;
}

// void	form_beSigned_test()
// {
// 	std::cout << "\n";
// 	std::cout << YELLOW << "# AForm::beSigned Test" << RESET << std::endl << "\n";

// 	// Bureaucrat can't sign cus too low grade
// 	Bureaucrat	b1("Alpha", 50);
// 	AForm		f1("A", 45, 45);

// 	b1.signForm(f1);

// 	// Bureaucrat can sign
// 	Bureaucrat	b2("Beta", 40);

// 	b2.signForm(f1);
// 	b2.signForm(f1); // Double sign
// }

int main()
{
	ocf_test();
	exception_class();
	increase_grade();
	decrease_grade();
	intern_makeformtest();
	// form_beSigned_test(); // abstract class cannot instantiate
	return 0;
}
