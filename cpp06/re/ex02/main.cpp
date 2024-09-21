
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *s = generate();
    
    identify(s);
    identify(*s);
    
    delete s;
    return 0;
}