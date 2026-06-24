#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        PresidentialPardonForm();
        std::string _target;
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        void execute(Bureaucrat const & executor) const;
        std::string get_target() const;
        ~PresidentialPardonForm();
};

#endif
