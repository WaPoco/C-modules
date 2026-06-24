#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        RobotomyRequestForm();
        std::string _target;
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        std::string get_target() const;
        void execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
};

#endif