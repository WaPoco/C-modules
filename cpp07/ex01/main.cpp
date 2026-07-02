#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T &value)
{
    std::cout << value << " ";
}

template <typename T>
void increment(T &value)
{
    value++;
}

void toUpper(std::string &str)
{
    for (std::size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original numbers: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    iter(numbers, 5, increment<int>);

    std::cout << "After increment: ";
    iter(numbers, 5, print<int>);
    std::cout << std::endl;

    std::string words[] = {"hello", "world", "cpp"};

    std::cout << "Original strings: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;

    iter(words, 3, toUpper);

    std::cout << "Uppercase strings: ";
    iter(words, 3, print<std::string>);
    std::cout << std::endl;

    const double values[] = {1.1, 2.2, 3.3};

    std::cout << "Const doubles: ";
    iter(values, 3, print<double>);
    std::cout << std::endl;

    return 0;
}