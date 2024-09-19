
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *s = generate();
    
    identify(s);
    identify(*s);
    
    return 0;
}