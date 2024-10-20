#include "BitcoinExchange.hpp"
#include <sstream>
BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}

t_date tostruct(std::string str)
{
    t_date date;
    std::string price;
    price = str.substr(str.find(',') + 1, str.size() - str.find(','));
    date.price = stod(price, 0);
    str.resize(str.find(','));
    date.date = str;
    return date;
}

void BitcoinExchange::import_data()
{
    std::string str;
    t_date tmp;
    std::ifstream file_data("data.csv");
    if (!file_data.is_open())
        throw("Is not open ");
    else
    {
        int i = 0;
        for (;;)
        {
            if (!std::getline(file_data, str))
                break;
            if (i > 0)
            {
                tmp = tostruct(str);
                _data.insert({tmp.date, tmp.price});
            }
            i++;
        }
    }
    file_data.close();
}

t_date BitcoinExchange::serch_to_date(std::string str)
{
    t_date date;

    for (auto it : _data)
    {
        if (it.first <= str)
        {
            date.date = it.first;
            date.price = it.second;
        }
    }
    return date;
}