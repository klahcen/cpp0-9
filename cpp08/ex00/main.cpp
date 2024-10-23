
#include "easyfind.hpp"
#include <vector>

int main()
{
    try{
        std::vector<int> n;
        for(int i=0; i<10; i++)
            n.push_back(i);
        easyfind(n, 1);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    } 

}