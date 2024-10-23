#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    mstack.push(10);
    mstack.push(110);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    int i = 0;
    std::cout << "****************************" << std::endl;
    while (it != ite)
    {
        std::cout << i++ << ": " << *it << std::endl;
        ++it;
    }
    std::cout << "****************************" << std::endl;
    i = 0;
    while (!mstack.empty())
    {
        std::cout << i++ << ": " << mstack.top() << std::endl;
        mstack.pop();
    }
    std::stack<int> s(mstack);
    return 0;
}
