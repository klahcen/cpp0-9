
#include "Point.hpp"

int main()
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point h(2, -2.01f);

   

    if(bsp(a, b, c, h))
        std::cout<< "Inside"<< std::endl;
    else
       std::cout<<"Outside"<<std::endl;
    return 0;
}