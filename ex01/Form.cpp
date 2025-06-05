#include "Form.hpp"

Form::Form(const std::string p_name, const int p_gradeToSign, const int p_gradeToExecute):
	_name(p_name), _isSigned(false), _gradeToSign(p_gradeToSign), _gradeToExecute(p_gradeToExecute)
{
	if (p_gradeToSign < 1 || p_gradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else if (p_gradeToSign > 150 || p_gradeToExecute > 150)
		throw (Form::GradeTooLowException());
	std::cout << MAGENTA << "[Form] " << GREEN << "Parameter constructor called\n" << RESET;
	std::cout << _name << " : ";
	std::cout << "GradeToSign->" << _gradeToSign << " : ";
	std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
}

Form::Form(const Form &other):
	_name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << MAGENTA << "[Form] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << _name << " : ";
	std::cout << "GradeToSign->" << _gradeToSign << " : ";
	std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
}

/*
	All three _name, _GradeToSign and _GradeToExecute are const, so not needed to modify in copy assignment?
*/
Form	&Form::operator=(const Form &other)
{
	std::cout << MAGENTA << "[Form] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != other)
	{
		setIsSigned(other._isSigned);
		std::cout << _name << " : ";
		std::cout << "GradeToSign->" << _gradeToSign << " : ";
		std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
	}
	return (*this);
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

const int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void	Form::setIsSigned(bool p_isSigned)
{
	this->_isSigned = p_isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

std::string	Form::printFormSignedStatus(void)
{
	if (this->_isSigned == true)
		return ("Yes");
	else
		return ("No");
}

/*
	It changes the form status to signed if the bureaucrat’s grade is high enough
	(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
	If the grade is too low, throw a Form::GradeTooLowException.
*/
void	Form::beSigned(Bureaucrat &ObjBureaucrat)
{
	if (ObjBureaucrat.getGrade() <= this->_gradeToSign)
	{
		if (this->_isSigned == false)
			this->_isSigned = true;
		else
			std::cout << "Form was signed already!" << std::endl;
	}
	else
		throw (Form::GradeTooLowException());
}

/*
	Prints all Form information
*/
std::ostream	&operator<<(std::ostream &output, const Form &other)
{
	output << std::endl;
	output << "-----" << other.getName() << " 's Form Information-----" << std::endl;
	output << "Form Name: " << other.getName() << std::endl;
	output << "Is Signed: " << other.printFormSignedStatus() << std::endl;
	output << "GradeToSign: " << other.getGradeToSign() << std::endl;
	output << "GradeToExecute: " << other.getGradeToExecute() << std::endl;
}
