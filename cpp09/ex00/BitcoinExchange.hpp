#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

typedef struct s_date
{
    std::string date;
    double price;
} t_date;

class BitcoinExchange
{
private:
    std::map<std::string, double> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    const BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void import_data();
    t_date serch_to_date(std::string str);
};
#endif