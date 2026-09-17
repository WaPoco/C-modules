#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include "BitcoinExchange.hpp"

int main(int argv, char **args)
{
    (void)args;
    if (argv <= 1)
    {
        fprintf(stderr, "Error: Couldn't open file.");
        return (0);
    }
    BitcoinExchange exchange;
    exchange.LoadData();
    exchange.ReadData(args[1]);
    return (0);
}