#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PP_Form", 25, 5), _target("Default_PP")
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string p_target):
	AForm("PP_Form", 25, 5), _target(p_target)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Parameter constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm("PP_Form", 25, 5), _target(other._target)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
		std::cout << this->_target << "->" << this->getName()
			<< " | Sign: " << this->getGradeToSign() << " | Execute: "
			<< this->getGradeToExecute() <<  " | is created!\n";
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Destructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is destroyed!\n";
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	// AForm::execute_check(executor);
	std::cout << executor.getName() << " executed " << this->getName() << " form\n";
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN 
		<< this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &output, const PresidentialPardonForm &other)
{
	output << std::endl;
	output << "-----" << other.getName() << " 's AForm Information-----" << std::endl;
	output << "AForm Name: " << other.getName() << std::endl;
	output << "Is Signed: " << other.printAFormSignedStatus() << std::endl;
	output << "GradeToSign: " << other.getGradeToSign() << std::endl;
	output << "GradeToExecute: " << other.getGradeToExecute() << std::endl;
	return (output);
}
