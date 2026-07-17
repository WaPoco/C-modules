#pragma once

#include<map>
#include<string>
#include<fstream>
#include<iostream>

class BitcoinExchange
{
    private:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        std::map<std::string, double> database;
    public:
        void ReadData();
};