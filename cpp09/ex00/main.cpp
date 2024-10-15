#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            std::cout << av[1] << std::endl;
            BitcoinExchange f;
            f.import_data();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout<<"Error: could not open file."<<std::endl;
    return 0;
}