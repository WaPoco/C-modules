#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>

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
    private:
        const std::string name;
        int _grade;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif