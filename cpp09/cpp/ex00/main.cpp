#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <string>
#include <sstream>


bool isValidfloat(const std::string& str) {
    if (str.empty()) return false;  

    size_t i = 0;
    if (str[i] == '+' || str[i] == '-') {  
        i++; 
    }

    bool hasDecimal = false;
    bool hasDigits = false;

    for (; i < str.size(); ++i) {
        if (isdigit(str[i])) {
            hasDigits = true;  
        } else if (str[i] == '.') {
            if (hasDecimal) return false; 
            hasDecimal = true;
        } else {
            return false; 
        }
    }

    return hasDigits;  
}

bool isNumber(const std::string& str) {
    if (str.empty()) return false;

    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int ft_stoi(std::string str)
{
    if(!isNumber(str))
        throw std::runtime_error("Error: bad date => "+str+".");
    float num;
    std::stringstream ss(str);
    ss >> num;

    if (ss.fail()) {
        throw std::runtime_error("Error: bad date => "+str+".");
    } 
    else {
        return num;
    }
}

float ft_stod(std::string str)
{
    if(!isValidfloat(str))
        throw std::runtime_error("Error: bad date => "+str+".");
    float num;
    std::stringstream ss(str);
    ss >> num;

    if (ss.fail()) {
        throw std::runtime_error("Error: bad date => "+str+".");
    } 
    else {
        return num;
    }
}


std::string parsing_date(std::string date)
{
    size_t pos = date.find("-");
    if(pos==std::string::npos)
         throw std::runtime_error("Error: bad date.");
    std::string year = date.substr(0,pos);
    std::string str = date.substr(pos+1,date.size());
    pos = str.find("-");
    if(pos == std::string::npos)
         throw std::runtime_error("Error: bad date.");
    std::string month = str.substr(0,pos);
    std::string day = str.substr(pos+1,str.size());
    if(ft_stoi(year)>2050||ft_stoi(year)<2009)
         throw std::runtime_error("Error: bad date.");
    if(ft_stoi(month)>12||ft_stoi(month)<0) 
         throw std::runtime_error("Error: bad date.");
    if(ft_stoi(day)>30||ft_stoi(day)<0)
         throw std::runtime_error("Error: bad date.");
    return date;
}
float parsing_price(std::string price)
{
    float nbr;
     size_t i = 0;
    while (i < price.size() && std::isspace(price[i])) {
        i++;
    }
    nbr = ft_stod(price.substr(i));
    if(nbr<0)
        throw std::runtime_error("Error: not a positive number.");
    if(nbr>1000)
        throw std::runtime_error("Error: too large a number.");
    return nbr;
}

void start(std::string str,BitcoinExchange data)
{
    (void)data;
    size_t pos = str.find("|");
    if(pos==std::string::npos)
        throw std::runtime_error("Error: bad date => "+str+".");
    std::string date = str.substr(0, pos);
    std::string price = str.substr(pos+1, str.size());
    date = parsing_date(date.erase(date.find_last_not_of(" ") + 1));
    float nbr = parsing_price(price.erase(price.find_last_not_of(" ")+1));
    std::cout << date << "=> " << nbr << " = " << nbr * data.serch_to_date(date).price << std::endl;
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
                BitcoinExchange data;
                data.import_data();
                for (;;)
                {
                    if (!std::getline(file_data, str))
                        break;
                    if (i == 0)
                    {
                        if (str != "date | value")
                            throw std::runtime_error("Error in form of file.");
                    }
                    else
                    {
                        try
                        {
                            start(str,data);
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