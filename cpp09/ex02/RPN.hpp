#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
private:
    std::stack<char> _data;

public:
    // RPN();
    // RPN(const RPN &other);
    // const RPN &operator=(const RPN &other);
    // ~RPN();
    void store_data(const char *str);
    // std::stack<char> ft_Reverse_stack();
};

#endif