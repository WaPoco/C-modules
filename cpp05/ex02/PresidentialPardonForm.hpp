#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    int _gradeToSign;
    int _gradeToExecute;
    PresidentialPardonForm();
    PresidentialPardonForm(int gradeToSign, int gradeToExecute);
    void execute() const;
    ~PresidentialPardonForm();
};

#endif
