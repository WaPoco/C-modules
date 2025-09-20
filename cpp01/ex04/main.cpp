#include <string>
#include <iostream>
#include <fstream>

bool    file_exist(std::string file)
{
    std::ifstream test(file);
    if (!test)
    {
        std::cout << "File " << file << " doesn't exit!" << std::endl;
        return (false);
    }
    test.close();
    return (true);
} 

int main(int argc, char **args)
{
    std::string s1 = args[2];
    std::string s2 = args[3];
    size_t      start_index;
    std::string line;
    std::string head;
    std::string tail;
    std::string input = "";
    std::string res = "";

    if (!args[2] || args[2][0] == '\0')
    {
        std::cout << "Argument 2 can't be empty!" << std::endl;
        return (1); 
    }
    if (!file_exist(args[1]))
        return (1); 
    std::ifstream myfile (args[1]);
    while (std::getline(myfile, line))
        input += line + "\n";
//    std::cout << input << std::endl;
    myfile.close();
    input = input.substr(0, input.size() - 1);
    start_index = input.find(s1);
//  std::cout << start_index << std::endl;
    while (start_index != std::string::npos)
    {
        head = input.substr(0, start_index);
//        std::cout << "head:" << head << std::endl;
        tail = input.substr(start_index + s1.size(), input.size() - (start_index + s1.size()));
//        std::cout << "tail:" << tail << std::endl;
        input = head + s2 + tail;
        start_index = input.find(s1, start_index + s2.size() - 1);
//        std::cout << start_index << std::endl;
    }
//    std::cout << input << std::endl;
    std::ofstream replace_myfile ("replace." + (std::string)args[1], std::ios::trunc);
    replace_myfile << input;
    myfile.close();
    return (0);
}