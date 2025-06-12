#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

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


	std::ofstream::open() in C++98 expects a C-style string (const char*), not a std::string
	Convert the std::string to a C-style string using .c_str():
*/
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::execute_check(executor);
	std::ofstream	outfile;
	std::string		filename;

	filename = this->getTarget() + "_shrubbery";
	outfile.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!outfile.is_open())
		throw (ShrubberyCreationForm::FileFailedOpenException());
	std::cout << executor.getName() << " executed " << this->getName() << " form\n";
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

std::ostream	&operator<<(std::ostream &output, const ShrubberyCreationForm &other)
{
	output << std::endl;
	output << "-----" << other.getName() << " 's AForm Information-----" << std::endl;
	output << "AForm Name: " << other.getName() << std::endl;
	output << "Is Signed: " << other.printAFormSignedStatus() << std::endl;
	output << "GradeToSign: " << other.getGradeToSign() << std::endl;
	output << "GradeToExecute: " << other.getGradeToExecute() << std::endl;
	return (output);
}
