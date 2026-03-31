#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToExecute < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExecute > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
}

int Form::get_gradeToSign() const
{
    return _gradeToSign;
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

void Form::set_name(std::string& name)
{
    _name = name;
}

void Form::set_gradeToSign(const int &gradeToSign)
{
    _gradeToSign = gradeToSign;
}

void Form::set_isSigned(const int &isSigned)
{
    _isSigned = isSigned;
}

void Form::set_gradeToExecute(const int &gradeToExecute)
{
    _gradeToExecute = gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() >= get_gradeToSign())
        set_isSigned(true);
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << f.get_name() << ", form grade to sign " << f.get_gradeToSign() << ", form grade to execute " << f.get_gradeToExecute() << std::endl;
    return (os);
}
