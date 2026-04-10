#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ... " << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << _target << " has been robotomized unsuccessfully." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
}