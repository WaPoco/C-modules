#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **args)
{
    std::string s1 = args[2];
    std::string s2 = args[3];
    std::string text;
    std::string res = "";
    std::string end;

    std::ifstream myfile ("file0");
    while (std::getline(myfile, text))
        res += text;
    std::cout << res << std::endl;
    int end1 = res.find(s1);
    res.copy(end, ...);
    myfile.close();
    return (0);
}