#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat():_name("")
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    else
        _grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (os);
}

void Bureaucrat::signForm(Form& form)
{
    try 
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}

