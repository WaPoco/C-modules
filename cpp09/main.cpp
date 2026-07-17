#include<map>
#include<string>
#include<fstream>
#include<iostream>

int main(int argv, char **args)
{
    if (argv <= 1)
    {
        fprintf(stderr, "Error:Couldn't open file.");
        return (0);
    }
    std::map<std::string, double> database;
    std::ifstream file("data.csv");
    std::string line;

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    return (0);
}