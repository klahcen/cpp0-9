#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) {}
const RPN &RPN::operator=(const RPN &other) { return *this; }
RPN::~RPN() {}
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

// void RPN::store_data(const char *S)
// {
//     std::string str(S);
//     int reslt = 0;
//     int first_elem = 10;
//     int i = 0;
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (i == str.size() - 1 && (!check_operator(str[i]) && str[i] != '
//         '))
//             throw std::runtime_error("Error1");

//         if (str[i] != ' ')
//         {
//             if ((str[i] >= '0' && str[i] <= '9') || str[i] == '*' || str[i]
//             == '+' || str[i] == '-' || str[i] == '/')
//             {
//                 _data.push(str[i]);
//             }
//             else
//                 throw std::runtime_error("Error11");
//         }
//     }
//     ft_Reverse_stack(_data);
//     if (_data.empty())
//         throw std::runtime_error("Error");
//     while (!_data.empty())
//     {
//         if (i == 0)
//         {
//             reslt = _data.top() - '0';
//         }
//         else if (i == 1)
//         {
//             if (check_operator(_data.top()))
//                 throw std::runtime_error("Error2");
//             first_elem = _data.top() - '0';
//         }
//         else if (check_operator(_data.top()))
//         {
//             if (first_elem != 10)
//             {
//                 if (_data.top() == '+')
//                     reslt += first_elem;
//                 else if (_data.top() == '-')
//                     reslt -= first_elem;
//                 else if (_data.top() == '*')
//                     reslt *= first_elem;
//                 else if (_data.top() == '/')
//                 {
//                     if (first_elem == 0)
//                         throw std::runtime_error("Error33");
//                     reslt /= first_elem;
//                 }
//                 first_elem = 10;
//             }
//             else
//                 throw std::runtime_error("Error3");
//         }
//         else if (first_elem == 10)
//             first_elem = _data.top() - '0';
//         else
//             throw std::runtime_error("Error4");
//         _data.pop();
//         i++;
//     }
//     std::cout << reslt << std::endl;
// }

void RPN::store_data(const char *S)
{
    std::string str(S);
    int reslt = 0;
    int fir_elem = 0;
    int sec_elem = 0;
    int i = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (i == str.size() - 1 && (!check_operator(str[i]) && str[i] != ' '))
            throw std::runtime_error("Error");

        if (str[i] != ' ')
        {
            if ((str[i] >= '0' && str[i] <= '9') || check_operator(str[i]))
            {
                if (!check_operator(str[i]))
                    _data.push(str[i] - '0');
                else
                {
                    sec_elem = _data.top();
                    _data.pop();
                    if (_data.empty())
                        throw std::runtime_error("Error");
                    fir_elem = _data.top();
                    _data.pop();
                    if (str[i] == '+')
                        fir_elem += sec_elem;
                    else if (str[i] == '-')
                        fir_elem -= sec_elem;
                    else if (str[i] == '*')
                        fir_elem *= sec_elem;
                    else if (str[i] == '/')
                    {
                        if (sec_elem == 0)
                            throw std::runtime_error("Error");
                        fir_elem /= sec_elem;
                    }
                    _data.push(fir_elem);
                }
            }
            else
                throw std::runtime_error("Error");
        }
    }
    if (_data.size() == 1)
        std::cout << _data.top() << std::endl;
    else
        throw std::runtime_error("Error");
}