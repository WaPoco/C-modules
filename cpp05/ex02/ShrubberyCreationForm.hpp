#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    ShrubberyCreationForm();
    ShrubberyCreationForm(AForm& form);
    void execute() const;
    ~ShrubberyCreationForm();
};

#endif