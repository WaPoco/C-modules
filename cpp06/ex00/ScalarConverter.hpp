# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

class ScalarConverter
{
    private:
        std::string input;
        ScalarConverter();
        ScalarConverter(std::string &str);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();
    public:
        static void convert(std::string &str);
};

static bool isInt(std::string &s);
static void isChar(std::string &s);
static void isDouble(std::string &s);
static void isFloat(std::string &s);

#endif