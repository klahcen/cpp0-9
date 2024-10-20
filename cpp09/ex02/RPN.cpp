#include "RPN.hpp"

bool check_operator(char c)
{
    if (c == '-' || c == '+' || c == '*' || c == '/')
        return true;
    return false;
}

void ft_Reverse_stack(std::stack<char> &_data)
{
    std::stack<char> tmp;
    while (!_data.empty())
    {
        tmp.push(_data.top());
        _data.pop();
    }
    _data = tmp;
}

void RPN::store_data(const char *S)
{
    std::string str(S);
    int reslt = 0;
    int first_elem = 10;
    int i = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (i == str.size() - 1 && !check_operator(str[i]))
            throw std::runtime_error("Error1");

        if (str[i] != ' ')
        {
            if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
            {
                _data.push(str[i]);
            }
            else
                throw std::runtime_error("Error11");
        }
    }
    ft_Reverse_stack(_data);
    while (!_data.empty())
    {
        if (i == 0)
        {
            reslt = _data.top() - '0';
        }
        else if (i == 1)
        {
            if (check_operator(_data.top()))
                throw std::runtime_error("Error2");
            first_elem = _data.top() - '0';
        }
        else if (check_operator(_data.top()))
        {
            if (first_elem != 10)
            {
                if (_data.top() == '+')
                    reslt += first_elem;
                else if (_data.top() == '-')
                    reslt -= first_elem;
                else if (_data.top() == '*')
                    reslt *= first_elem;
                else if (_data.top() == '/'){
                    if(first_elem == 0)
                        throw std::runtime_error("Error33");
                    reslt /= first_elem;
                }
                first_elem = 10;
            }
            else
                throw std::runtime_error("Error3");
        }
        else if (first_elem == 10)
            first_elem = _data.top() - '0';
        else
            throw std::runtime_error("Error4");
        _data.pop();
        i++;
    }
    std::cout << reslt << std::endl;
}