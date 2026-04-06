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
        void signForm();
        void executeForm(AForm const & form);
    private:
        const std::string name;
        int _grade;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif