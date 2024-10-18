#include "BitcoinExchange.hpp"

void pars_date(std::string str)
{
    std::cout<<str<<std::endl;
    std::string Str = str;
    std::string str1=str;
    std::string str2;
    std::string str3;
    str1.resize(str1.find('-'));
    std::cout<<str1<<std::endl;
    str2 = str;
    str2 = str2.substr(str2.find('-')+1, str2.size() - str2.find('-'));
    str2.resize(str2.find('-'));
    std::cout<<str2<<std::endl;
    str3 = str;
    str3 = str3.substr(str3.find('-')+1, str3.size() - str3.find('-'));
    str3.resize(str3.find('-')-str2.size());
    std::cout<<str3<<std::endl;
    // std::cout<<str1<<"|"<<str2<<"|"<<str3<<std::endl;
}

void tostruct_to_input(std::string str, int i)
{
    t_date date;
    t_date date_from_baiz;
    std::string price;
    std::string Str;
    BitcoinExchange data;

    Str = str;
    if (i == 0)
    {
        if (str != "date | value")
            throw std::runtime_error("Error in form of file");
    }
    else
    {
        if (str.find('|') > str.size())
            throw std::runtime_error("Error: bad input => " + str);
        price = str.substr(str.find('|') + 2, str.size() - str.find('|'));
        date.price = std::stod(price);
        if (date.price > 1000)
            throw std::runtime_error("Error: too large a number.");
        else if (date.price < 0)
            throw std::runtime_error("Error: not a positive number.");
        str.resize(str.find('|'));
        date.date = str;
        pars_date(date.date);
        data.import_data();
        date_from_baiz = data.serch_to_date(date.date);
        // std::cout << date.date << "=> " << date.price << " = " << date.price * date_from_baiz.price << std::endl;
    }
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
                    try
                    {
                        tostruct_to_input(str, i);
                    }
                    catch (std::exception &e)
                    {
                        std::cout << e.what() << std::endl;
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