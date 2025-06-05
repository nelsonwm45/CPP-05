#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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

/**
 * const char* what() const throw()
 * @brief is a part of std::exception in C++
 * - You need to override this function when you inherit
 * - const - The function does not modify the object.
 * - throw() - This function promises the compiler that it will never throw any exceptions.
 * 
 * @bug the following example is breaking promise, using throw() exception in a "No throwing exceptions"
 * 	const char* what() const throw() {
 * 	throw std::runtime_error("Boom!");  // ❌ NOT ALLOWED
 * @brief use "return" instead
 * const char* what() const throw() {
 * return "Grade too low!";
}

}

 */

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat(std::string p_name, int p_grade); // constructor
		Bureaucrat(const Bureaucrat &other); // copy contructor
		Bureaucrat &operator=(const Bureaucrat &other); // copy assignment operator
		~Bureaucrat(); // destructor

		const std::string getName(void) const;
		int getGrade(void) const;
		// void	setName(std::string p_name);
		void	setGrade(int p_grade);

		// Exception classes 
		// pdf asked us to throw 2 exceptions: GradeTooLowException, GradeTooHighException
		class	GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		void	downGrade();
		void	upGrade();

		void	signForm(Form &objForm);

};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &other);

#endif
