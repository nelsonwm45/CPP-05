#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

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

#include "AForm.hpp"
// inheritance must provide full include, means implementation is needed, so must use #include AFORM here
// class	AForm; 

class	Bureaucrat;

class	ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm(void);

	public:
		ShrubberyCreationForm(std::string p_target); // constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other); // copy constructor
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); // copy assignment operator
		~ShrubberyCreationForm(void); // destructor

		// Getters & Setters
		std::string	getTarget(void) const;

		class	FileFailedOpenException: public	std::exception
		{
			public:
				const char* what() const throw();
		};

		void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &output, const ShrubberyCreationForm &other);

#endif