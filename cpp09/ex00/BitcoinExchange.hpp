#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

typedef struct s_date
{
    std::string date;
    int price;
} t_date;

class BitcoinExchange
{
private:
    std::vector<t_date> _vector_date;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    const BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    void import_data();
};

#endif