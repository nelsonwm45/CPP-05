#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
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
// class	Bureaucrat;

class	PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(std::string p_target); // constructor
		PresidentialPardonForm(const PresidentialPardonForm &other); // copy constructor
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other); // copy assignment operator
		~PresidentialPardonForm(void); // destructor

		// Getters & Setters
		std::string	getTarget(void) const;

		void	execute(void);
};

#endif