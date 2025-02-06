#include "BitcoinExchange.hpp"

bool ft_isdigit(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            if (!isdigit(str[i]))
            {
                std::cout << str[i] << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool ft_isdigit_price(std::string str)
{
    int n = std::count(str.begin(), str.end(), '.');
    if (n > 1)
        return false;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ' && str[i] != '.')
        {
            if (!isdigit(str[i]))
                return false;
        }
    }
    return true;
}

void pars_date(std::string str)
{
    int n = std::count(str.begin(), str.end(), '-');
    if (str.empty() || n != 2)
        throw std::runtime_error("Error: bad date");
    std::string year;
    std::string months;
    std::string day;

    year = str;
    months = str;
    day = str;
    year.resize(year.find('-'));
    months = str.substr(year.size() + 1, str.size() - str.find('-') + 1);
    months.resize(months.find('-'));
    day = str.substr(months.size() + year.size() + 2, str.size());
    if (!ft_isdigit(year) || !ft_isdigit(months) || !ft_isdigit(day))
        throw std::runtime_error("Error bad date1");
    if (year.empty() || months.empty() || day.empty())
        throw std::runtime_error("Error: bad date");
    if (atoi(year.c_str()) < 2009 || atoi(year.c_str()) > 2090)
        throw std::runtime_error("Error: bad date");
    if (atoi(months.c_str()) < 1 || atoi(months.c_str()) > 12)
        throw std::runtime_error("Error: bad date");
    if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31)
        throw std::runtime_error("Error: bad date");
}

void tostruct_to_input(std::string str)
{
    t_date date;
    t_date date_from_baiz;
    std::string price;
    std::string Str;
    BitcoinExchange data;
    char *endptr;

    Str = str;
    if (str.find('|') > str.size())
        throw std::runtime_error("Error: bad input => " + str);
    price = str.substr(str.find('|') + 2, str.size() - str.find('|'));
    date.price = std::strtod(price.c_str(), &endptr);
    if (*endptr != '\0')
        throw std::runtime_error("Error in price");
    if (date.price > 1000)
        throw std::runtime_error("Error: too large a number.");
    else if (date.price < 0)
        throw std::runtime_error("Error: not a positive number.");
    str.resize(str.find('|'));
    date.date = str;
    pars_date(date.date);
    data.import_data();
    date_from_baiz = data.serch_to_date(date.date);
    std::cout << date.date << "=> " << date.price << " = " << date.price * date_from_baiz.price << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            std::ifstream file_data(av[1]);
            if (!file_data.is_open())
                throw std::runtime_error("Is not open");
            else
            {
                std::string str;
                t_date tmp;
                int i = 0;
                for (;;)
                {
                    if (!std::getline(file_data, str))
                        break;
                    if (i == 0)
                    {
                        if (str != "date | value")
                            throw std::runtime_error("Error in form of file");
                    }
                    else
                    {
                        try
                        {
                            tostruct_to_input(str);
                        }
                        catch (std::exception &e)
                        {
                            std::cout << e.what() << std::endl;
                        }
                    }
                    i++;
                }
            }
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Error: could not open file." << std::endl;
    return 0;
}