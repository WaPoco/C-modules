#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    RobotomyRequestForm();
    RobotomyRequestForm(AForm& form);
    void execute() const;
    ~RobotomyRequestForm();
};

#endif