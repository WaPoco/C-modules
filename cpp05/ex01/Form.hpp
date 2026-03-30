#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form : public Bureaucrat
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
        std::string getter_name() const;
        int getter_gradeToSign() const;
        bool getter_isSigned() const;
        int getter_gradeToExecute() const;
        // setter
        void setter_name(std::string& const name);
        void setter_gradeToSign(const int& gradeToSign);
        void setter_isSigned(const int& isSigned);
        void setter_gradeToExecute(const int& gradeToExecute);
        void beSigned(Bureaucrat& b);
};

#endif