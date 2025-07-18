#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
const RPN &RPN::operator=(const RPN &other)
{
  if (this != &other)
    this->_data = other._data;
  return *this;
}
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

void RPN::store_data(const char *S)
{
  std::string str(S);
  int fir_elem = 0;
  int sec_elem = 0;
  for (size_t i = 0; i < str.size(); i++)
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