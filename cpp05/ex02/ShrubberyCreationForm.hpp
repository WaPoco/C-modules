#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    ShrubberyCreationForm();
    ShrubberyCreationForm(AForm& form);
    void execute(Bureaucrat const & executor) const;
    ~ShrubberyCreationForm();
};

#endif