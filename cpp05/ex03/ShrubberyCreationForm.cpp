#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
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
    AForm::execute(executor);
    std::ofstream ofs((_target + "_shrubbery").c_str());
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