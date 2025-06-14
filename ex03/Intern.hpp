#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <stdexcept> // for std::exception

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

class	AForm;

class	Intern
{
	private:

	public:
		Intern(void); // default constructor
		Intern(const Intern &other); // copy constructor
		Intern	&operator=(const Intern &other); // copy assignment operator
		~Intern();

		AForm	*makeForm(const std::string form_name, const std::string form_target) const;

		class	FormNotExistException: public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		AForm	*makeRobotomyForm(const std::string target) const;
		AForm	*makePresidentialForm(const std::string target) const;
		AForm	*makeShrubberyForm(const std::string target) const;
};


#endif