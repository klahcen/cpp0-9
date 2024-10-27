#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
private:
    std::stack<int> _data;

public:
    RPN();
    RPN(const RPN &other);
    const RPN &operator=(const RPN &other);
    ~RPN();
    void store_data(const char *str);
};

#endif