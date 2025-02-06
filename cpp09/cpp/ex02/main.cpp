#include "PmergeMe.hpp"

bool check_first_char(char c)
{
  if (c == '-' || c == '+' || std::isdigit(c))
    return true;
  return false;
}

int pars_input(char *str)
{
  int nbr = 0;
  char *endptr;
  int i = 1;
  while (str[i])
  {
    if (!check_first_char(str[0]) || (std::strtod(str, &endptr) == 0 && str[0] != '0') || !std::isdigit(str[i++]) || i > 11)
      throw std::runtime_error("Error");
  }
  nbr = std::strtod(str, &endptr);
  if(*endptr != '\0'||nbr<0)
      throw std::runtime_error("Error");
  return nbr;
}

int main(int ac, char **av)
{
  int i = 1;
  Pmergeme pmergeme;
  if (ac > 1)
  {
    try
    {
      int nbr = 0;
      while (i < ac)
      {
        nbr = pars_input(av[i]);
        pmergeme.vector.push_back(nbr);
        pmergeme.deque.push_back(nbr);
        i++;
      }
      std::cout << "Before: ";
      for (size_t i = 0; i < pmergeme.vector.size(); i++)
        std::cout << pmergeme.vector[i] << " ";
      std::cout << std::endl;
      std::clock_t start_time_vector = std::clock();
      pmergeme.merge_sort(&pmergeme.vector);
      std::clock_t end_time_vector = std::clock();
      double duration_vector = double(end_time_vector - start_time_vector) / CLOCKS_PER_SEC;
      std::clock_t start_time_deque = std::clock();
      pmergeme.merge_sort(&pmergeme.deque);
      std::clock_t end_time_deque = std::clock();
      double duration_deque = double(end_time_deque - start_time_deque) / CLOCKS_PER_SEC;
      std::cout << "After : ";
      for (size_t i = 0; i < pmergeme.deque.size(); i++)
        std::cout << pmergeme.deque[i] << " ";
      std::cout << std::endl;
      std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << duration_vector << std::endl;
      std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << duration_deque << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  else
    std::cout << "Error" << std::endl;
  return 0;
}