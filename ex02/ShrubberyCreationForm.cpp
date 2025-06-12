#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
// #include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("SC_Form", 145, 137), _target("Default_SC")
{
	std::cout << MAGENTA << "[ShrubberyCreationForm] " << GREEN << "Default constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string p_target):
	AForm("SC_Form", 145, 137), _target(p_target)
{
	std::cout << MAGENTA << "[ShrubberyCreationForm] " << GREEN << "Parameter constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm("SC_Form", 145, 137), _target(other._target)
{
	std::cout << MAGENTA << "[ShrubberyCreationForm] " << GREEN << "Copy constructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is created!\n";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << MAGENTA << "[ShrubberyCreationForm] " << GREEN << "Copy assignment operator called\n" << RESET;
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

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << MAGENTA << "[ShrubberyCreationForm] " << GREEN << "Destructor called\n" << RESET;
	std::cout << this->_target << "->" << this->getName()
		<< " | Sign: " << this->getGradeToSign() << " | Execute: "
		<< this->getGradeToExecute() <<  " | is destroyed!\n";
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

const char *ShrubberyCreationForm::FileFailedOpenException::what() const throw ()
{
	return ("ShrubberyCreationForm: Failed to Open File");
}

/*
	std::ofstream::out – Open for writing.
	std::ofstream::trunc – Truncate (clear) the file if it already exists.
*/
void	ShrubberyCreationForm::execute(void)
{
	std::ofstream	outfile;
	std::string		filename;

	filename = this->getTarget() + "_shrubbery";
	outfile.open(filename, std::ofstream::out | std::ofstream::trunc);
	if (!outfile.is_open())
		throw (ShrubberyCreationForm::FileFailedOpenException());
	outfile << "\n"
		<< "         ###\n"
		<< "        #o###\n"
		<< "       #####o###\n"
		<< "      #o#\\\\#|#/###\n"
		<< "     ###\\\\|/#o#o##\n"
		<< "    #o#\\\\#|#/###o##\n"
		<< "   ###\\\\|/#o#\\\\#|#o#\n"
		<< "      ||||| |||\n"
		<< "      ||||| |||\n"
		<< "      ||||| |||\n"
		<< "       |||   |||\n";

	std::cout << filename << " created in working directory\n";
}
