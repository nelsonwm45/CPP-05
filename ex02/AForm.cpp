#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void):
	_name("Default_Form"), _isSigned(false), _gradeToSign(2), _gradeToExecute(2)
{
	std::cout << MAGENTA << "[AForm] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << _name << " : ";
	std::cout << "GradeToSign->" << _gradeToSign << " : ";
	std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
}

AForm::AForm(const std::string p_name, const int p_gradeToSign, const int p_gradeToExecute):
	_name(p_name), _isSigned(false), _gradeToSign(p_gradeToSign), _gradeToExecute(p_gradeToExecute)
{
	if (p_gradeToSign < 1 || p_gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (p_gradeToSign > 150 || p_gradeToExecute > 150)
		throw (AForm::GradeTooLowException());
	std::cout << MAGENTA << "[AForm] " << GREEN << "Parameter constructor called\n" << RESET;
	std::cout << _name << " : ";
	std::cout << "GradeToSign->" << _gradeToSign << " : ";
	std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
}

AForm::AForm(const AForm &other):
	_name(other._name), _isSigned(other._isSigned), 
	_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << MAGENTA << "[AForm] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << _name << " : ";
	std::cout << "GradeToSign->" << _gradeToSign << " : ";
	std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
}

/*
	All three _name, _GradeToSign and _GradeToExecute are const, so not needed to modify in copy assignment?
*/
AForm	&AForm::operator=(const AForm &other)
{
	std::cout << MAGENTA << "[AForm] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		std::cout << _name << " : ";
		std::cout << "GradeToSign->" << _gradeToSign << " : ";
		std::cout << "GradeToExecute->" << _gradeToExecute << std::endl;
	}
	return (*this);
}


AForm::~AForm(void)
{
	std::cout << MAGENTA << "[AForm] " << GREEN << "Destructor called\n" << RESET;
	std::cout << _name << " : " << " is destroyed!" << std::endl;
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form Class Exception: Grade Too High!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form Class Exception: Grade Too Low!");
}

const char *AForm::AFormAlreadySigned::what() const throw()
{
	return ("Form Class Exception: The AForm Was Already Signed Before!");
}

std::string	AForm::printAFormSignedStatus(void) const
{
	if (this->_isSigned == true)
		return ("Yes");
	else
		return ("No");
}

/*
	It changes the form status to signed if the bureaucrat’s grade is high enough
	(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
	If the grade is too low, throw a AForm::GradeTooLowException.
*/
void	AForm::beSigned(Bureaucrat &ObjBureaucrat)
{
	if (ObjBureaucrat.getGrade() <= this->_gradeToSign)
	{
		if (this->_isSigned == false)
			this->_isSigned = true;
		else
			throw (AForm::AFormAlreadySigned());
	}
	else
		throw (AForm::GradeTooLowException());
}

/*
	Prints all AForm information
*/
std::ostream	&operator<<(std::ostream &output, const AForm &other)
{
	output << std::endl;
	output << "-----" << other.getName() << " 's AForm Information-----" << std::endl;
	output << "AForm Name: " << other.getName() << std::endl;
	output << "Is Signed: " << other.printAFormSignedStatus() << std::endl;
	output << "GradeToSign: " << other.getGradeToSign() << std::endl;
	output << "GradeToExecute: " << other.getGradeToExecute() << std::endl;
	return (output);
}


/********************************  EX02  **************************************/

const char *AForm::AFormNotSignedYet::what() const throw()
{
	return ("Form Class Exception: The Form is Not Signed Yet!");
}

/*
	add the execute(Bureaucrat const & executor) const member function to
 	the base form and implement a function to execute the form’s action of the concrete
 	classes. You have to check that the form is signed and that the grade of the bureaucrat
 	attempting to execute the form is high enough. Otherwise, throw an appropriate excep
	tion

	since Bureaucrat will execute form using AForm::execute, so this function will be virtual fx
	virtual fx does not need implementation

	void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	if (this->printAFormSignedStatus() == false)
		throw (AForm::AFormNotSignedYet());
}

	BUT still have to do execute check before executing, so add one more function for execute check
*/
void	AForm::execute_check(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowException());
	if (this->getIsSigned() == false)
		throw (AForm::AFormNotSignedYet());
}
