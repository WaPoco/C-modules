#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "AForm.hpp"
# include <string>

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);
        void executeForm(AForm const & form);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat::GradeTooHighException: Grade is too high!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat::GradeTooLowException: Grade is too low!";
                }
        };
        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "FormNotSignedException: Form is not signed!";
                }
        };
    private:
        const std::string name;
        int _grade;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif