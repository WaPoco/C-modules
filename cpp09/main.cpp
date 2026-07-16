#include<map>
#include<string>
#include<fstream>
#include<iostream>

int main()
{
    std::map<std::string, double> database;
    std::ifstream file("data.csv");
    std::string line;

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    return (0);
}