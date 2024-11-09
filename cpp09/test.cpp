
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template <typename type> 
struct my_allo: allocator<type>{
    type*allocate(int size)
    {
        std::cout<<"Allocator = "<<size<<std::endl;
        return new type [size];
    }
    void deallocate(type *ptr, int size)
    {
        cout<<"deallocation size = "<<size<<endl;
        delete [] ptr;
    } 
};

int main()
{
    std::vector<int , my_allo<int> > v;
    std::deque<int , my_allo<int> > d;
    d.push_back(0);
    return 0;
}
