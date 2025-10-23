#include <iostream>
#include <fstream>
#include <string.h>

void    replace(std::string& input, std::string& s1, std::string& s2, std::string& filename)
{
    size_t      start_index;
    std::string head;
    std::string tail;
    std::string result;

    start_index = input.find(s1);
    while (s1 != s2 && start_index != std::string::npos)
    {
        head = input.substr(0, start_index);
        tail = input.substr(start_index + s1.size(), input.size() - (start_index + s1.size()));
        input = head + s2 + tail;
        start_index = input.find(s1, start_index + s2.size() - 1);
    }
    result = "replace." + filename;
    std::ofstream replace_myfile (result.c_str(), std::ios::trunc);
    replace_myfile << input;
    replace_myfile.close();
}

std::string readfile(std::string& filename)
{
    std::string line;
    std::string input;

    std::ifstream myfile (filename.c_str());

    while (std::getline(myfile, line))
        input += line + "\n";
    myfile.close();
    return input;   
}

bool    file_exist(std::string file)
{
    std::ifstream test(file.c_str());
    if (!test)
    {
        std::cerr << "File " << file << " doesn't exit!" << std::endl;
        return (false);
    }
    test.close();
    return (true);
} 

int main(int argc, char **args)
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::string input = "";

    if (argc != 4)
    {
        std::cerr << "Not enough arguments" << std::endl;
        return (1);
    }
    filename = args[1];
    s1 = args[2];
    if (s1.empty())
    {
        std::cerr << "s1 can't be empty!" << std::endl;
        return (1);
    }
    s2 = args[3];
    if (!file_exist(args[1]))
        return (1);
    input = readfile(filename);
    input = input.substr(0, input.size() - 1);
    replace(input, s1, s2, filename);
    return (0);
}