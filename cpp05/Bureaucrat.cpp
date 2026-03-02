#include <iostream>
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    try
    {
        if (grade < 1)
            throw GradeTooLowException();
        else if (grade > 150)
            throw GradeTooHighException();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

