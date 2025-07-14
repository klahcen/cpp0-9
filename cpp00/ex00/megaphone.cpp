
#include <iostream>

int main(int ac, char **av)
{
    int j;
    if (ac > 1)
    {
        for(int i = 1; i < ac; i++)
        {
            j = 0;
            while (av[i][j])
            {
                if(av[i][j]>= 97 && av[i][j] <= 122)
                    std::cout << (char)(av[i][j]-32);
                else
                    std::cout << av[i][j];
                j++;
            }
        }
        std::cout<<std::endl;
    }
    else
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
    return 0;
}