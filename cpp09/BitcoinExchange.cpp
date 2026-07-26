#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return (*this);
}

BitcoinExchange::validateDateRate()
{

}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::ReadData()
{
    std::string line;

    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "Error: couldn't open file" << std::endl;
        return ;
    }
    // skip header
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t comma = line.find(',');

        if (comma == std::string::npos)
            std::cout << "Error format " << std::endl;
        else
        {
            std::string date = line.substr(0, comma);
            std::string rate = line.substr(comma + 1);
            validateDateRate(date, rate);
            double exchange_rate = std::stod(rate);
            database[date] = exchange_rate;
        }
    }
    file.close();
}