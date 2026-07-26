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

bool BitcoinExchange::validateDate(std::string date)
{
    std::string yearStr;
    std::string monthStr;
    std::string dayStr;
    int         year;
    int         days;
    int         month;
    char        extra;

    std::stringstream ss(date);

    if (!std::getline(ss, yearStr, '-'))
        return false;
    if (!std::getline(ss, monthStr, '-'))
        return false;
    if (!std::getline(ss, dayStr))
        return false;
    
    if (monthStr.length() != 2 || dayStr.length() != 2)
        return false;

    std::stringstream ys(yearStr);
    std::stringstream ms(monthStr);
    std::stringstream ds(dayStr);

    if (!(ys >> year) || (ys >> extra))
        return false;
    if (!(ms >> month) || (ms >> extra))
        return false;
    if (!(ds >> days) || (ds >> extra))
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leap = (year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0);

    if (leap)
        daysInMonth[1] = 29;

    if (days < 1 || days > daysInMonth[month - 1])
        return false;
        
    return true;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::ReadData(std::string filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: Couldn't open file." << std::endl;
        return;
    }

    std::string line;

    if (!std::getline(file, line) || line != "date | value")
    {
        std::cout << "Error: Invalid input file." << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') ||
            !std::getline(ss, valueStr))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Remove spaces around date/value
        while (!date.empty() && date[date.size() - 1] == ' ')
            date.erase(date.size() - 1);

        while (!valueStr.empty() && valueStr[0] == ' ')
            valueStr.erase(0, 1);

        if (!validateDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value;
        char extra;

        std::stringstream vs(valueStr);

        if (!(vs >> value) || (vs >> extra))
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::iterator it =
            database.lower_bound(date);

        if (it == database.end())
        {
            --it;
        }
        else if (it->first != date)
        {
            if (it == database.begin())
            {
                std::cout << "Error: no exchange rate available."
                          << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date
                  << " => "
                  << value
                  << " = "
                  << value * it->second
                  << std::endl;
    }

    file.close();
}

void BitcoinExchange::LoadData()
{
    std::string line;
    std::string date;
    std::string rateStr;
    double      rate;
    char        extra;

    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "Error: Couldn't open file" << std::endl;
        return ;
    }
    if (!std::getline(file, line) || line != "date,exchange_rate")
    {
        std::cout << "Error: Loading data." << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        
        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
        {
            std::cout << "Error: Invalid input. " << std::endl;
            return ;
        }
        if (!validateDate(date))
        {
            std::cout << "Error: Date format incorrect." << std::endl;
            return ;
        }
        std::stringstream rS(rateStr);
        if (!(rS >> rate) || (rS >> extra) || rate < 0)
        {
            std::cout << "Error: Invalid rate" << std::endl;
            return ;
        }
        database[date] = rate;
    }
    file.close();
}
