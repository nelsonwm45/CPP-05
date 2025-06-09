#ifndef AFORM_HPP
# define AFORM_HPP

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

class Bureaucrat; // Always use forward declaration in header, Use "include" in .cpp

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
 * }
 * @brief use "return" instead
 * const char* what() const throw() {
 * return "Grade too low!";
	}

 */

class	AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	public:
		AForm(const std::string p_name, const int p_gradeToSign, const int p_gradeToExecute); // constructor
		AForm(const AForm &other); // copy contructor
		AForm &operator=(const AForm &other); // copy assignment operator
		virtual ~AForm(); // destructor

		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		std::string			printAFormSignedStatus(void) const;

		// Exception classes 
		// pdf asked us to throw 2 exceptions: GradeTooLowException, GradeTooHighException
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	AFormAlreadySigned: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		void	beSigned(Bureaucrat &ObjBureaucrat);
};

std::ostream	&operator<<(std::ostream &output, const AForm &other);

#endif
