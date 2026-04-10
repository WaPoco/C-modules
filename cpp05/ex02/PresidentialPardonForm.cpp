#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardonForm", 25, 5)
{
    _target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}