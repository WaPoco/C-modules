#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm():_name(""), _gradeToSign(0), _gradeToExecute(0)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::~AForm()
{
}

std::string AForm::get_name() const
{
    return _name; 
}

int AForm::get_gradeToSign() const
{
    return _gradeToSign;
}

bool AForm::get_isSigned() const
{
    return _isSigned;
}

int AForm::get_gradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::set_isSigned(const int &isSigned)
{
    _isSigned = isSigned;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= get_gradeToSign())
        set_isSigned(true);
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form: " << f.get_name() << std::endl;
    os << "Signed: " << f.get_isSigned() << std::endl;
    os << "Grade required to sign: " << f.get_gradeToSign() << std::endl;
    os << "Grade required to execute: " << f.get_gradeToExecute() << std::endl;
    return (os);
}

void AForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (get_isSigned() == false)
            throw Bureaucrat::FormNotSignedException();
        if (executor.getGrade() > get_gradeToExecute())
            throw Bureaucrat::GradeTooLowException();
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

AForm::AForm(const AForm &other):_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}
