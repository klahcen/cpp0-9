#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class Pmergeme
{
  public :
    Pmergeme();
    Pmergeme(const Pmergeme *other);
    const Pmergeme &operator=(const Pmergeme &other);
    ~Pmergeme();
    std::deque<int> deque;
    std::vector<int> vector;
    void merge_sort(std::deque<int> *stack);
    void merge_sort(std::vector<int> *stack);
};

#endif