#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name("Default_Bureaucrat"), _grade(150)
{
	std::cout << MAGENTA << "[Bureaucrat] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << _name << " : " << _grade << std::endl;
}

/*
	Grade : 1 is highest, 150 is the lowest
*/
Bureaucrat::Bureaucrat(std::string p_name, int p_grade):
	_name(p_name)
{
	if (p_grade < 1)
		throw (GradeTooHighException());
	else if (p_grade > 150)
		throw (GradeTooLowException());
	else
		this->_grade = p_grade;
	std::cout << MAGENTA << "[Bureaucrat] " << GREEN << "Parameter constructor called\n" << RESET;
	std::cout << _name << " : " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name), _grade(other._grade)
{
	std::cout << MAGENTA << "[Bureaucrat] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << _name << " : " << _grade << std::endl;
}

/*
	since name is const type, so you can change it after construction
*/
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << MAGENTA << "[Bureaucrat] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		setGrade(other.getGrade());
		std::cout << _name << " : " << _grade << std::endl;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << MAGENTA << "[Bureaucrat] " << GREEN << "Destructor called\n" << RESET;
	std::cout << _name << " : " << _grade << " is destroyed!" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int p_grade)
{
	this->_grade = p_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low!");
}

/*
	Decrease Grade, means increase the value
	max value is 150
*/
void	Bureaucrat::downGrade()
{
	if (this->_grade == 150)
	{
		std::cout << RED << "This bureaucrat has lowest grade (150)! No way to decrease !" << RESET << std::endl;
		return ;
	}
	this->_grade++;
}

/*
	Increase Grade, means decrease the value
	min value is 1
*/
void	Bureaucrat::upGrade()
{
	if (this->_grade == 1)
	{
		std::cout << RED << "This bureaucrat has highest grade (1)! No way to increase !" << RESET << std::endl;
		return ;
	}
	this->_grade--;
}

/*
	You will implement an overload of the insertion («) operator to print something like
	(without the angle brackets):
	<name>, bureaucrat grade <grade>
*/
std::ostream	&operator<<(std::ostream &output, const Bureaucrat &other)
{
	output << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (output);
}
