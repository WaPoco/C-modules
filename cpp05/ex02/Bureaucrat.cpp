#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm &form)
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

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn't execute " << form.get_name() << " because " << e.what() << std::endl;
    }
}
