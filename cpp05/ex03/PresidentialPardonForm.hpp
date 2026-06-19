#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        std::string _target;
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};

#endif
