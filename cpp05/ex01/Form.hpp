#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>


class Bureaucrat;

class Form
{
    private:
        Form();
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form& other);
        ~Form();
        // getter
        std::string get_name() const;
        int get_gradeToSign() const;
        bool get_isSigned() const;
        int get_gradeToExecute() const;
        void set_isSigned(const int& isSigned);
        void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif