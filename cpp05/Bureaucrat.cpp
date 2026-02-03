#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooLowException;
        else if (grade > 150)
            throw Bureaucrat::GradeTooHighException;
    }
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
    // TODO: insert return statement here
}

int Bureaucrat::getGrade() const
{
    return 0;
}

void Bureaucrat::incrementGrade()
{
}

void Bureaucrat::decrementGrade()
{
}

