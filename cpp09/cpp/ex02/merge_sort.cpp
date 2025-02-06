#include "PmergeMe.hpp"


void merge(std::vector<int> right_stack, std::vector<int> left_stack, std::vector<int> *stack)
{
  size_t l = 0;
  size_t r = 0;
  size_t i = 0;
  while (l < left_stack.size() && r < right_stack.size())
  {
    if (left_stack[l] < right_stack[r])
    {
      stack->at(i) = (left_stack[l]);
      l++;
    }
    else
    {
      stack->at(i) = (right_stack[r]);
      r++;
    }
    i++;
  }
  while (r < right_stack.size())
  {
    stack->at(i) = (right_stack[r]);
    i++;
    r++;
  }
  while (l < left_stack.size())
  {
    stack->at(i) = (left_stack[l]);
    l++;
    i++;
  }
}
void merge_sort_low(std::vector<int> *stack)
{
  if (stack->size() <= 1)
    return;
  std::vector<int> right_stack;
  std::vector<int> left_stack;
  size_t i = 0;
  for (; i < stack->size(); i++)
  {
    if (i < stack->size() / 2)
      right_stack.push_back(stack->at(i));
    else
      left_stack.push_back(stack->at(i));
  }
  merge_sort_low(&right_stack);
  merge_sort_low(&left_stack);

  merge(right_stack, left_stack, stack);
}

//deque

void merge(std::deque<int> right_stack, std::deque<int> left_stack, std::deque<int> *stack)
{
  size_t l = 0;
  size_t r = 0;
  size_t i = 0;
  while (l < left_stack.size() && r < right_stack.size())
  {
    if (left_stack[l] < right_stack[r])
    {
      stack->at(i) = (left_stack[l]);
      l++;
    }
    else
    {
      stack->at(i) = (right_stack[r]);
      r++;
    }
    i++;
  }
  while (r < right_stack.size())
  {
    stack->at(i) = (right_stack[r]);
    i++;
    r++;
  }
  while (l < left_stack.size())
  {
    stack->at(i) = (left_stack[l]);
    l++;
    i++;
  }
}
void merge_sort_low(std::deque<int> *stack)
{
  if (stack->size() <= 1)
    return;
  std::deque<int> right_stack;
  std::deque<int> left_stack;
  size_t i = 0;
  for (; i < stack->size(); i++)
  {
    if (i < stack->size() / 2)
      right_stack.push_back(stack->at(i));
    else
      left_stack.push_back(stack->at(i));
  }
  merge_sort_low(&right_stack);
  merge_sort_low(&left_stack);

  merge(right_stack, left_stack, stack);
}