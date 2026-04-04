#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string _name;
        bool _isSigned;
        int _gradeToSign;
        int _gradeToExecute;
    public:
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        ~Form();
        // getter
        std::string get_name() const;
        int get_gradeToSign() const;
        bool get_isSigned() const;
        int get_gradeToExecute() const;
        // setter
        void set_name(std::string& name);
        void set_gradeToSign(const int& gradeToSign);
        void set_isSigned(const int& isSigned);
        void set_gradeToExecute(const int& gradeToExecute);
        void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif