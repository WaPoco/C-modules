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
        bool isInt(std::string &s);
        void isChar(std::String &s);
        void isDouble();
        void isFloat();
};

#endif