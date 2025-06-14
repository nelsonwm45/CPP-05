#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
	std::cout << MAGENTA << "[Intern] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << "Intern was constructed!\n";
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << MAGENTA << "[Intern] " << GREEN << "Copy constructor called\n" << RESET;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << MAGENTA << "[Intern] " << GREEN << "Copy assignment operator called\n" << RESET;
	return (*this);
}

Intern::~Intern()
{
	std::cout << MAGENTA << "[Intern] " << GREEN << "Destructor called\n" << RESET;
}

const char	*Intern::FormNotExistException::what() const throw()
{
	return ("Intern Exception : Form Name Not Exist!");
}

AForm	*Intern::makePresidentialForm(const std::string target) const
{
	std::cout << "Intern creates Presidential Pardon Form" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyForm(const std::string target) const
{
	std::cout << "Intern creates Robotomy Request Form" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyForm(const std::string target) const
{
	std::cout << "Intern creates Shrubbery Creation Form" << std::endl;
	return (new ShrubberyCreationForm(target));
}

/**
 * because return the pointer of the AForm, so I need to use "new" to return;
 * @brief typedef to give a simple name to complex type
 * 	typedef AForm* (Intern::*FormCreator)(const std::string);
 * 
 * @attention Can also dont use typedef, it's still doing the same things which create *formCreators[]
 * 	AForm* (Intern::* formCreators[])(const std::string) = {
 * &Intern::makeRobotomyForm,
 * &Intern::makePresidentialForm,
 * &Intern::makeShrubberyForm
 * };
 * 
 * typedef AForm* (Intern::*FormCreator)(const std::string);	Defines FormCreator as a nickname for a pointer-to-Intern-member-function
 * FormCreator formCreators[] = {...};	Declares an array of pointers to Intern’s form creation member functions
 * (this->*formCreators[i])(form_target);	Calls the function pointer at index i on this Intern
 */
AForm	*Intern::makeForm(const std::string form_name, const std::string form_target) const
{
	AForm	*return_form;

	// Declare an array of form_name to compare
	const std::string	available_form[] =
	{
		"RobotomyRequestForm",
		"PresidentialPardonForm",
		"ShrubberyCreationForm",
	};

	// Declare an array of function pointers which its order correspond to form_name above
	// FormCreator is an alias
	// (this->*formCreators[i])(form_target);	Calls the function pointer at index i on this Intern
	typedef	AForm* (Intern::*FormCreator)(const std::string) const;
	FormCreator	formCreator[] = 
	{
		&Intern::makeRobotomyForm,
		&Intern::makePresidentialForm,
		&Intern::makeShrubberyForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_name.compare(available_form[i]) == 0)
		{
			return_form = (this->*formCreator[i])(form_target);
			return (return_form);
		}
	}

	// If compare everything, all not found then throw exception
	throw (Intern::FormNotExistException());
}
	
// AForm	*Intern::makeForm(const std::string form_name, const std::string form_target) const
// {
// 	AForm	*return_form;

// 	const std::string	available_form[] =
// 	{
// 		"RobotomyRequestForm",
// 		"PresidentialPardonForm",
// 		"ShrubberyCreationForm",
// 	};
// 	typedef	AForm* (Intern::*FormCreator)(const std::string);
// 	FormCreator	FormCreator[] = 
// 	{
// 		&Intern::makeRobotomyForm,
// 		&Intern::makePresidentialForm,
// 		&Intern::makeShrubberyForm
// 	};
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (form_name.compare(available_form[i]) == 0)
// 			break;
// 	}
// 	if (i == 3)
// 		throw (Intern::FormNotExistException());
// 	switch (i)
// 	{
// 		case 0:
// 			return_form = makeRobotomyForm(target);
// 			break;
// 		case 1:
// 			return_form = makePresidentialForm(target);
// 			break;
// 		case 2:
// 			return_form = makeShrubberyForm(target);
// 			break;
// 	}
// 	return (return_form);
// }
