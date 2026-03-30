#include <iostream>
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return (name);
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

void Bureaucrat::signForm()
{
    if (Form::beSigned(Bureaucrat::getGrade()))
    std::cout << name << " signs form." << std::endl;
}
