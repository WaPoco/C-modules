#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        AForm* makeForm(const std::string &name, const std::string &target);
        ~Intern();
    };

AForm* createShrubbery(const std::string& target);
AForm* createRobotomy(const std::string& target);
AForm* createPardon(const std::string& target);