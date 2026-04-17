# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter
{
    private:
        std::string input;
    public:
        ScalarConverter();
        ~ScalarConverter();
        static void convert(std::string str);
        void isInt();
        void isChar();
        void isDouble();
        void isFloat();
};

#endif