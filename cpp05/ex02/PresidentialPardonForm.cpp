#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include "FormNotSignedException.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5)
{
    _target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute();
    std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}