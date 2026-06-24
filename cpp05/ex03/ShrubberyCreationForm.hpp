#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        ShrubberyCreationForm();
        std::string _target;
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        std::string get_target() const;
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        void execute(Bureaucrat const & executor) const;
        ~ShrubberyCreationForm();
};

#endif