#include "PmergeMe.hpp"

Pmergeme::Pmergeme() {}
Pmergeme::Pmergeme(const Pmergeme *other)
{
    *this = other;
}
const Pmergeme &Pmergeme::operator=(const Pmergeme &other)
{
    if (this != &other)
    {
    }
    return *this;
}
Pmergeme::~Pmergeme() {}

int bainary_search(std::vector<int> lorgest, int x)
{
    if (x > lorgest.at(lorgest.size() - 2))
        return lorgest.size() - 1;
    for (size_t i = 0; i < lorgest.size() - 1; i++)
    {
        if (lorgest[i] >= x && lorgest[i + 1] && lorgest[i + 1] >= x)
        {
            return (i);
        }
    }
    return -1;
}

std::vector<std::pair<int, int> > Pairing_elements(std::vector<int> *stack, size_t size)
{
    std::vector<std::pair<int, int> > tmp;
    if (size % 2 != 0)
    {
        size -= 1;
    }
    tmp.reserve(size / 2);
    for (size_t i = 0; i < size; i += 2)
    {
        tmp.push_back(std::make_pair((*stack)[i], (*stack)[i + 1]));
    }

    return tmp;
}
std::vector<std::pair<int, int> > Sorting_pairs(std::vector<std::pair<int, int> > tmp_vector)
{
    int tmp = 0;
    for (size_t i = 0; i < tmp_vector.size(); i++)
    {
        if (tmp_vector[i].first < tmp_vector[i].second)
        {
            tmp = tmp_vector[i].first;
            tmp_vector[i].first = tmp_vector[i].second;
            tmp_vector[i].second = tmp;
        }
    }
    return tmp_vector;
}

std::vector<std::pair<int, int> > Sorting_the_Pairs(std::vector<std::pair<int, int> > tmp_vector)
{

    for (size_t i = 0; i < tmp_vector.size(); i++)
    {
        for (size_t j = i + 1; j < tmp_vector.size(); j++)
        {
            if (tmp_vector[i].first > tmp_vector[j].first)
            {
                swap(tmp_vector[i], tmp_vector[j]);
            }
        }
    }
    return tmp_vector;
}

void Create_two_sequences(std::vector<int> *lorgest, std::vector<int> *lowest, std::vector<std::pair<int, int> > tmp_vector)
{
    for (size_t i = 0; i < tmp_vector.size(); i++)
    {
        lorgest->push_back(tmp_vector[i].first);
        lowest->push_back(tmp_vector[i].second);
    }
}

void Pmergeme::merge_sort(std::vector<int> *stack)
{
    if (stack->size() < 6)
        merge_sort_low(stack);
    else
    {
        std::vector<int> lorgest;
        std::vector<int> lowest;
        std::vector<int> tmp;
        std::vector<std::pair<int, int> > tmp_vector;
        size_t size = stack->size();
        int index = -1;
        tmp_vector = Pairing_elements(stack, size);
        tmp_vector = Sorting_pairs(tmp_vector);
        tmp_vector = Sorting_the_Pairs(tmp_vector);
        lorgest.reserve(size);
        lowest.reserve(size / 2);
        Create_two_sequences(&lorgest, &lowest, tmp_vector);
        for (size_t i = 0; i < lowest.size(); i++)
        {
            if (i > 0)
                index = bainary_search(lorgest, lowest[i]);
            else
                index = 0;
            if (index == -1)
                throw std::runtime_error("Error1");
            std::vector<int>::iterator it = lorgest.begin() + index;
            lorgest.insert(it, lowest[i]);
        }
        if (size % 2)
        {
            index = bainary_search(lorgest, stack->at(size - 1));
            std::vector<int>::iterator it = lorgest.begin() + index;
            lorgest.insert(it, stack->at(size - 1));
        }
        *stack = lorgest;
    }
}

// deque

int bainary_search(std::deque<int> lorgest, int x)
{
    if (x > lorgest.at(lorgest.size() - 2))
        return lorgest.size() - 1;
    for (size_t i = 0; i < lorgest.size() - 1; i++)
    {
        if (lorgest[i] >= x && lorgest[i + 1] && lorgest[i + 1] >= x)
        {
            return (i);
        }
    }
    return -1;
}

std::deque<std::pair<int, int> > Pairing_elements(std::deque<int> *stack, size_t size)
{
    std::deque<std::pair<int, int> > tmp;
    if (size % 2 != 0)
    {
        size -= 1;
    }
    for (size_t i = 0; i < size; i += 2)
    {
        tmp.push_back(std::make_pair((*stack)[i], (*stack)[i + 1]));
    }

    return tmp;
}
std::deque<std::pair<int, int> > Sorting_pairs(std::deque<std::pair<int, int> > tmp_vector)
{
    int tmp = 0;
    for (size_t i = 0; i < tmp_vector.size(); i++)
    {
        if (tmp_vector[i].first < tmp_vector[i].second)
        {
            tmp = tmp_vector[i].first;
            tmp_vector[i].first = tmp_vector[i].second;
            tmp_vector[i].second = tmp;
        }
    }
    return tmp_vector;
}

std::deque<std::pair<int, int> > Sorting_the_Pairs(std::deque<std::pair<int, int> > tmp_vector)
{

    for (size_t i = 0; i < tmp_vector.size(); i++)
    {
        for (size_t j = i + 1; j < tmp_vector.size(); j++)
        {
            if (tmp_vector[i].first > tmp_vector[j].first)
            {
                swap(tmp_vector[i], tmp_vector[j]);
            }
        }
    }
    return tmp_vector;
}

void Create_two_sequences(std::deque<int> *lorgest, std::deque<int> *lowest, std::deque<std::pair<int, int> > tmp_vector)
{
    for (size_t i = 0; i < tmp_vector.size(); i++)
    {
        lorgest->push_back(tmp_vector[i].first);
        lowest->push_back(tmp_vector[i].second);
    }
}

void Pmergeme::merge_sort(std::deque<int> *stack)
{
    if (stack->size() < 6)
        merge_sort_low(stack);
    else
    {
        std::deque<int> lorgest;
        std::deque<int> lowest;
        std::deque<int> tmp;
        std::deque<std::pair<int, int> > tmp_vector;
        size_t size = stack->size();
        int index = -1;
        tmp_vector = Pairing_elements(stack, size);
        tmp_vector = Sorting_pairs(tmp_vector);
        tmp_vector = Sorting_the_Pairs(tmp_vector);
        Create_two_sequences(&lorgest, &lowest, tmp_vector);
        for (size_t i = 0; i < lowest.size(); i++)
        {
            if (i > 0)
                index = bainary_search(lorgest, lowest[i]);
            else
                index = 0;
            if (index == -1)
                throw std::runtime_error("Error1");
            std::deque<int>::iterator it = lorgest.begin() + index;
            lorgest.insert(it, lowest[i]);
        }
        if (size % 2)
        {
            index = bainary_search(lorgest, stack->at(size - 1));
            std::deque<int>::iterator it = lorgest.begin() + index;
            lorgest.insert(it, stack->at(size - 1));
        }
        *stack = lorgest;
    }
}
