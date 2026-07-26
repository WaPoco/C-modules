#pragma once

#include<map>
#include<string>
#include<fstream>
#include<iostream>
#include <sstream>


class BitcoinExchange
{
    private:
        std::map<std::string, double> database;
    public:
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        bool validateDate(std::string date);
        ~BitcoinExchange();
        BitcoinExchange();
        void ReadData(std::string filename);
        void LoadData();
};