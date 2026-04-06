#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
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

void AForm::set_name(std::string& name)
{
    _name = name;
}

void AForm::set_gradeToSign(const int &gradeToSign)
{
    _gradeToSign = gradeToSign;
}

void AForm::set_isSigned(const int &isSigned)
{
    _isSigned = isSigned;
}

void AForm::set_gradeToExecute(const int &gradeToExecute)
{
    _gradeToExecute = gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() >= get_gradeToSign())
        set_isSigned(true);
    else
        std::cout << b.getName() << " signed" << get_name() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.get_name() << ", form grade to sign " << f.get_gradeToSign() << ", form grade to execute " << f.get_gradeToExecute() << std::endl;
    return (os);
}

void AForm::execute(Bureaucrat const &executor) const
{

}
