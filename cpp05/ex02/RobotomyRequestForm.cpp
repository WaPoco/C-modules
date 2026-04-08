#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include "FormNotSignedException.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute();
    std::cout << "BZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ... " << std::endl;
    if (rand() % 2)
        std::cout << executor.getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << executor.getName() << " has been robotomized unsuccessfully." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}