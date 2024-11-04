#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

template <class T>
int bainary_search(T lorgest, int x)
{
  if(x > lorgest.at(lorgest.size()-1))
    return lorgest.size();
  for (size_t i = 0; i < lorgest.size() - 1; i++)
  {
    if (lorgest[i] > x && lorgest[i + 1] && lorgest[i + 1] >= x)
    {
      return (i);
    }
  }
  return -1;
}

template <class T>
void inser_sort(T lorgest, T lowest, T *stack)
{
  typename T::iterator it = lorgest.begin();
  lorgest.insert(it, lowest.at(0));
  lowest.erase(lowest.begin());
  for (size_t i = 0; i < lowest.size(); i++)
  {
    int index = bainary_search(lorgest, lowest.at(i));
    if (index == -1)
      throw std::runtime_error("Error");
    else
    {
      it = lorgest.begin() + index;
      lorgest.insert(it, lowest.at(i));
    }
  }
  *stack = lorgest;
}

template <class T>
void sort_lorgest(T *lorgest, T *lowest)
{
  int tmp_low = 0;
  int tmp_loeg = 0;
  for (size_t i = 0; i < lorgest->size(); i++)
  {
    for (size_t j = i + 1; j < lorgest->size(); j++)
    {
      if (lorgest->at(i) > lorgest->at(j))
      {
        tmp_loeg = lorgest->at(i);
        tmp_low = lowest->at(i);
        lorgest->at(i) = lorgest->at(j);
        lowest->at(i) = lowest->at(j);
        lorgest->at(j) = tmp_loeg;
        lowest->at(j) = tmp_low;
      }
    }
  }
}

template <class T>
void merge_sort(T *stack)
{
  T lorgest;
  T lowest;
  size_t i = 0;
  int nbr = -1;
  if (stack->size() % 2)
  {
    typename T::iterator it = stack->end() - 1;
    nbr = stack->at(stack->size() - 1);
    stack->erase(it);
  }
  for (; i < stack->size() - 1; i += 2)
  {
    if (stack->at(i) >= stack->at(i + 1))
    {
      lorgest.push_back(stack->at(i));
      lowest.push_back(stack->at(i + 1));
    }
    else
    {
      lorgest.push_back(stack->at(i + 1));
      lowest.push_back(stack->at(i));
    }
  }
  sort_lorgest(&lorgest, &lowest);

  inser_sort(lorgest, lowest, stack);
  if(nbr!=-1)
  {
    typename T::iterator it = stack->begin();
    int index = bainary_search(*stack,nbr);
    if (index == -1)
      throw std::runtime_error("Error1");
    else
    {
      it = stack->begin() + index;
      stack->insert(it, nbr);
    }
  }
  lorgest.clear();
  lowest.clear();
}
#endif