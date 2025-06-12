#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

class	RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
		RobotomyRequestForm(void);

	public:
		RobotomyRequestForm(std::string p_target); // constructor
		RobotomyRequestForm(const RobotomyRequestForm &other); // copy constructor
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other); // copy assignment operator
		~RobotomyRequestForm(void); // destructor

		// Getters & Setters
		std::string	getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &output, const RobotomyRequestForm &other);

#endif