#include "BitcoinExchange.hpp"
#include <sstream>
BitcoinExchange::BitcoinExchange()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
}
const BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}

t_date tostruct(std::string str)
{
    t_date date;
    str.resize(str.find(','));
    date.date = str;
    date.price = 00;
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
            tmp = tostruct(str);
            if (i > 1)
                _vector_date.push_back(tmp);
            i++;
        }
    }
    for (auto it : _vector_date)
    {
        std::cout << it.date<<"|"<<it.price<< std::endl;
    }
    file_data.close();
}
