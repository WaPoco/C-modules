#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    public:
        std::string _target;
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        void execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();
};

#endif