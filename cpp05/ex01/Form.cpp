#include "Form.hpp"

Form::Form()
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
}

Form::~Form()
{
}

int Form::getter_gradeToSign() const
{
    return 0;
}

std::string Form::getter_name() const
{
    return _name; 
}

int Form::getter_gradeToSign() const
{
    return _gradeToSign;
}

bool Form::getter_isSigned() const
{
    return _isSigned;
}

int Form::getter_gradeToExecute() const
{
    return _gradeToExecute;
}

void Form::setter_name(std::string& const name)
{
    _name = name;
}

void Form::setter_gradeToSign(const int &gradeToSign)
{
    _gradeToSign = gradeToSign;
}

void Form::setter_isSigned(const int &isSigned)
{
    _isSigned = isSigned;
}

void Form::setter_gradeToExecute(const int &gradeToExecute)
{
    _gradeToExecute = gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() >= getter_gradeToSign())
        setter_isSigned(true);
}
