#include "Harl.hpp"

int main(int argc, char **args)
{
    Harls test;

    if (argc == 2)
        test.complain(args[1]);
    else
    {
        test.complain("DEBUG");
        test.complain("INFO");
        test.complain("WARNING");
        test.complain("ERROR");
    }
    return (0);
}