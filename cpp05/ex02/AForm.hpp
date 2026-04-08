#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string _name;
        bool _isSigned;
        int _gradeToSign;
        int _gradeToExecute;
    public:
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();
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
        virtual void execute(Bureaucrat const & executor) const;
        
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif