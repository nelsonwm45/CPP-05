#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RR_Form", 72, 45), _target("Default_RR")
{
	std::cout << MAGENTA << "[RobotomyRequestForm] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string p_target):
	AForm("RR_Form", 72, 45), _target(p_target)
{
	std::cout << MAGENTA << "[RobotomyRequestForm] " << GREEN << "Parameter constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm("RR_Form", 72, 45), _target(other._target)
{
	std::cout << MAGENTA << "[RobotomyRequestForm] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << MAGENTA << "[RobotomyRequestForm] " << GREEN << "Copy assignment operator called\n" << RESET;
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

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << MAGENTA << "[RobotomyRequestForm] " << GREEN << "Destructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is destroyed!\n";
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// AForm::execute_check(executor);
	std::cout << executor.getName() << " executed " << this->getName() << " form\n";
	std::cout << MAGENTA << "[RobotomyRequestForm] " << GREEN << "Making Some Drilling Noise"
		<< " ->DRRRRRRRRIIIIILLLLLLLL!" << RESET << std::endl;
	static int	SuccessCount = 0;

	if (SuccessCount % 2 != 0)
		std::cout << RED << "ROBOTOMY FAILED!" << RESET << std::endl;
	else
		std::cout << GREEN << "ROBOTOMY SUCCESS!" << RESET << std::endl;
	SuccessCount++;
}


std::ostream	&operator<<(std::ostream &output, const RobotomyRequestForm &other)
{
	output << std::endl;
	output << "-----" << other.getName() << " 's AForm Information-----" << std::endl;
	output << "AForm Name: " << other.getName() << std::endl;
	output << "Is Signed: " << other.printAFormSignedStatus() << std::endl;
	output << "GradeToSign: " << other.getGradeToSign() << std::endl;
	output << "GradeToExecute: " << other.getGradeToExecute() << std::endl;
	return (output);
}
