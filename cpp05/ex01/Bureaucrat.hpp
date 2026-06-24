#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include "Form.hpp"

class Bureaucrat
{
    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form& form);
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
    private:
        Bureaucrat();
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif