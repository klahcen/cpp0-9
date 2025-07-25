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
    char *endptr;
    price = str.substr(str.find(',') + 1, str.size() - str.find(','));
    date.price = strtod(price.c_str(), &endptr);
    if(*endptr!='\0')
        throw std::runtime_error("Error in price");
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
    {
        std::cerr<<"Is not open the data base"<<std::endl;
        exit (1);
    }
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
                _data[tmp.date] = tmp.price;
            }
            i++;
        }
    }
    file_data.close();
}

t_date BitcoinExchange::serch_to_date(std::string str)
{
    t_date date;

    std::map<std::string, double>::iterator it = _data.begin();
    for (it = _data.begin(); it != _data.end(); it++)
    {
        if (it->first <= str)
        {
            date.date = it->first;
            date.price = it->second;
        }
    }
    return date;
}