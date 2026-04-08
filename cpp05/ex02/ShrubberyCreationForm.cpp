#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include "FormNotSignedException.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute();
    std::ofstream ofs(get_name() + "_shrubbery");
    if (!ofs)
    {
        std::cerr << "Error creating file" << std::endl;
        return;
    }
    ofs << "       _-_" << std::endl;
    ofs << "    /~~   ~~\\" << std::endl;
    ofs << " /~~         ~~\\" << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~" << std::endl;
    ofs << "_- -   | |     _-" << std::endl;
    ofs << "  _ -  | |       -" << std::endl;
    ofs << "      // \\\\" << std::endl;
    ofs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}