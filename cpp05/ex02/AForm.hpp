#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
    private:
        AForm();
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm& other);
        virtual ~AForm();
        std::string get_name() const;
        int get_gradeToSign() const;
        bool get_isSigned() const;
        int get_gradeToExecute() const;
        void set_isSigned(const int& isSigned);
        void beSigned(Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif