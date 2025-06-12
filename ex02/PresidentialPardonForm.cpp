#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

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
	AForm("PP_Form", 25, 5), _target(other.p_target)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN << "Copy assignment operator called\n" << RESET;
	if (this != other)
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

void	PresidentialPardonForm::execute(void)
{
	std::cout << MAGENTA << "[PresidentialPardonForm] " << GREEN 
		<< this->_target << "has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}