
#include "easyfind.hpp"
#include <vector>
#include <stack>

int main()
{
    // try{
    //     std::vector<int> n;
    //     for(int i=0; i<10; i++)
    //         n.push_back(i);
    //     easyfind(n, 41);
    // }
    // catch(std::exception &e){
    //     std::cout<<e.what()<<std::endl;
    // } 


    try{
        std::stack<int> n;
        for(int i=0; i<10; i++)
            n.push(i);
        easyfind(n, 4);
    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }   
}