#pragma once

#include<map>
#include<string>
#include<fstream>
#include<iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        validateDateRate(std::string date, std:string rate);
        ~BitcoinExchange();
        BitcoinExchange();
        void ReadData();
};