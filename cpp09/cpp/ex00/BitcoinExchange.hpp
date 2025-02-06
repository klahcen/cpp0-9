#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <stdlib.h>

typedef struct s_date {
  std::string date;
  double price;
} t_date;

class BitcoinExchange {
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

bool ft_isdigit(std::string str);
#endif