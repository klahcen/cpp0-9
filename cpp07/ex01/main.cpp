
#include "iter.hpp"

int main()
{
    std::string arry[]={"haahahaha","lalala", "nanan", "kakakkaka", "shdfgsd", "sfhfhdg","jadhj"};
    size_t n = sizeof(arry)/sizeof(arry[0]);
    ::iter(arry, n,f);
    return 0;
}