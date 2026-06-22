#include "Intern.hpp"

typedef AForm* (*FormCreator)(const std::string&);

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    if (this != &other)
        *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
        *this = other;
    return (*this);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    FormCreator creators[3] = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == names[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cout << "Intern cannot create form: " << name << std::endl;
    return NULL;
}

Intern::~Intern()
{
}

AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}