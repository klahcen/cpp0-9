#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try
        {
            RPN v;
            v.store_data(av[1]);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "bad arguments" << std::endl;
    return 0;
}