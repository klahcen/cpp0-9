#include "PmergeMe.hpp"

Pmergeme::Pmergeme() {}
Pmergeme::Pmergeme(const Pmergeme *other)
{
    *this = other;
}
const Pmergeme &Pmergeme::operator=(const Pmergeme &other)
{
    if (this != &other){}
    return *this;
}
Pmergeme::~Pmergeme() {}

size_t Jacobsthal_sequence(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    return (Jacobsthal_sequence(x - 1) + 2 * Jacobsthal_sequence(x - 2));
}

int bainary_search(std::vector<int> lorgest, int x)
{
    if (x > lorgest.at(lorgest.size() - 2))
        return lorgest.size() - 1;
    for (size_t i = 0; i < lorgest.size() - 1; i++)
    {
        if (lorgest[i] > x && lorgest[i + 1] && lorgest[i + 1] >= x)
        {
            return (i);
        }
    }
    return lorgest.size()-1;
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
std::vector<int> get_index_lowest(std::vector<int> lowest)
{
    std::vector<int> index_lowest;
    int return_Jacobs=-1;
    int last_return_Jacobs=-1;
    for(size_t i=3; i<lowest.size();i++)
    {
        if(Jacobsthal_sequence(i)<=(lowest.size()))
        {
            return_Jacobs = Jacobsthal_sequence(i);
            last_return_Jacobs = Jacobsthal_sequence(i-1);
            for(int j = return_Jacobs; j>last_return_Jacobs;j--)
                  index_lowest.push_back(j);
        }
        else
        {
            int last = Jacobsthal_sequence(i-1);
            for(size_t j = last; j<lowest.size();j++)
                  index_lowest.push_back(j);
            break;
        }
    }
    return index_lowest;
}


void Pmergeme::merge_sort(std::vector<int> *stack)
{
    std::vector<int> lorgest;
    std::vector<int> lowest;
    std::vector<int> tmp;
    std::vector<int> index_lowest;
    std::vector<std::pair<int, int> > tmp_vector;
    size_t size = stack->size();
    if(size==1)
        return ;
    int index = -2;
    tmp_vector = Pairing_elements(stack, size);
    tmp_vector = Sorting_pairs(tmp_vector);
    tmp_vector = Sorting_the_Pairs(tmp_vector);
    lorgest.reserve(size);
    lowest.reserve(size / 2);
    Create_two_sequences(&lorgest, &lowest, tmp_vector);
    index_lowest = get_index_lowest(lowest);
    std::vector<int>::iterator it = lorgest.begin();
    lorgest.insert(it, lowest[0]);
    for (size_t i = 0; i < index_lowest.size(); i++)
    {
        if(i > lowest.size())
            break;
        index = bainary_search(lorgest, lowest[index_lowest[i]-1]);
        std::vector<int>::iterator it = lorgest.begin() + index;
        lorgest.insert(it, lowest[index_lowest[i]-1]);
    }
    if (size % 2)
    {
        index = bainary_search(lorgest, stack->at(size - 1));
        std::vector<int>::iterator it = lorgest.begin() + index;
        lorgest.insert(it, stack->at(size - 1));
    }
    *stack = lorgest;
}


//deque

int bainary_search(std::deque<int> lorgest, int x)
{
    if (x > lorgest.at(lorgest.size() - 2))
        return lorgest.size() - 1;
    for (size_t i = 0; i < lorgest.size() - 1; i++)
    {
        if (lorgest[i] > x && lorgest[i + 1] && lorgest[i + 1] >= x)
        {
            return (i);
        }
    }
    return lorgest.size() - 1;
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
std::deque<std::pair<int, int> > Sorting_pairs(std::deque<std::pair<int, int> > tmp_deque)
{
    int tmp = 0;
    for (size_t i = 0; i < tmp_deque.size(); i++)
    {
        if (tmp_deque[i].first < tmp_deque[i].second)
        {
            tmp = tmp_deque[i].first;
            tmp_deque[i].first = tmp_deque[i].second;
            tmp_deque[i].second = tmp;
        }
    }
    return tmp_deque;
}

std::deque<std::pair<int, int> > Sorting_the_Pairs(std::deque<std::pair<int, int> > tmp_deque)
{

    for (size_t i = 0; i < tmp_deque.size(); i++)
    {
        for (size_t j = i + 1; j < tmp_deque.size(); j++)
        {
            if (tmp_deque[i].first > tmp_deque[j].first)
            {
                swap(tmp_deque[i], tmp_deque[j]);
            }
        }
    }
    return tmp_deque;
}

void Create_two_sequences(std::deque<int> *lorgest, std::deque<int> *lowest, std::deque<std::pair<int, int> > tmp_deque)
{
    for (size_t i = 0; i < tmp_deque.size(); i++)
    {
        lorgest->push_back(tmp_deque[i].first);
        lowest->push_back(tmp_deque[i].second);
    }
}
std::deque<int> get_index_lowest(std::deque<int> lowest)
{
    std::deque<int> index_lowest;
    int return_Jacobs=-1;
    int last_return_Jacobs=-1;
    for(size_t i=3; i<lowest.size();i++)
    {
        if(Jacobsthal_sequence(i)<=(lowest.size()))
        {
            return_Jacobs = Jacobsthal_sequence(i)-1;
            last_return_Jacobs = Jacobsthal_sequence(i-1)-1;
            for(int j = return_Jacobs; j>last_return_Jacobs;j--)
                  index_lowest.push_back(j);
        }
        else
        {
            int last = Jacobsthal_sequence(i-1);
            for(size_t j = last; j<lowest.size();j++)
                  index_lowest.push_back(j);
            break;
        }
    }
    return index_lowest;
}


void Pmergeme::merge_sort(std::deque<int> *stack)
{
    std::deque<int> lorgest;
    std::deque<int> lowest;
    std::deque<int> tmp;
    std::deque<int> index_lowest;
    std::deque<std::pair<int, int> > tmp_deque;
    size_t size = stack->size();
    if(size==1)
        return ;
    int index = -1;
    tmp_deque = Pairing_elements(stack, size);
    tmp_deque = Sorting_pairs(tmp_deque);
    tmp_deque = Sorting_the_Pairs(tmp_deque);
    Create_two_sequences(&lorgest, &lowest, tmp_deque);
    index_lowest = get_index_lowest(lowest);
    for(size_t i=0;i < index_lowest.size();i++)
        std::cout<<index_lowest[i]<<" ";
    std::cout<<std::endl;
    std::deque<int>::iterator it = lorgest.begin();
    lorgest.insert(it, lowest[0]);
    for (size_t i = 0; i < index_lowest.size(); i++)
    {
        if(i>lowest.size())
            break;
        index = bainary_search(lorgest, lowest[index_lowest[i]-1]);
        std::deque<int>::iterator it = lorgest.begin() + index;
        lorgest.insert(it, lowest[index_lowest[i]-1]);
    }
    if (size % 2)
    {
        index = bainary_search(lorgest, stack->at(size - 1));
        std::deque<int>::iterator it = lorgest.begin() + index;
        lorgest.insert(it, stack->at(size - 1));
    }
    *stack = lorgest;
}