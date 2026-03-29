#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExecute;
};

#endif