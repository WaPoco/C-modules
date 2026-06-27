#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():_name(""), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw Bureaucrat::GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this); 
}

Form::~Form()
{
}

std::string Form::get_name() const
{
    return _name; 
}

int Form::get_gradeToSign() const
{
    return _gradeToSign;
}

bool Form::get_isSigned() const
{
    return _isSigned;
}

int Form::get_gradeToExecute() const
{
    return _gradeToExecute;
}

void Form::set_isSigned(const int &isSigned)
{
    _isSigned = isSigned;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= get_gradeToSign())
    {
        set_isSigned(true);
        std::cout << _name << " signed " << this->get_name() << std::endl;
    }
    else
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.get_name() << std::endl;
    os << "Signed: " << f.get_isSigned() << std::endl;
    os << "Grade required to sign: " << f.get_gradeToSign() << std::endl;
    os << "Grade required to execute: " << f.get_gradeToExecute() << std::endl;
    return (os);
}
