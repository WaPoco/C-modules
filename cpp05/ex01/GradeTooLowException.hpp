#ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP
#include <exception>

class GradeTooLowException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Bureaucrat::GradeTooLowException: Grade is too low!";
        }
};
#endif