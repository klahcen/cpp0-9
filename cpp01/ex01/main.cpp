
#include "Zombie.hpp"
#include <stdio.h>
int main()
{
    Zombie *zombie;
    std::string name= "lahcen";
    int N=12;

    zombie = zombieHorde( N, name);
    for(int i=0; i < N; i++)
        zombie[i].announce();
    delete[] zombie;
    return 0;
}