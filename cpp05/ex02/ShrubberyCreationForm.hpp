#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    public:
        std::string _target;
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        void execute(Bureaucrat const & executor) const;
        ~ShrubberyCreationForm();
};

#endif