
#include <iostream>
#include <vector>

int main(int ac, char **av) {
  int i = 1;
  std::vector<unsigned> vector;
  if (ac > 1) {
    while (av[i]) {
        vector.push_back(atoi(av[i]));
        i++;
    }
    for(auto it:vector)
std::cout<<it<<std::endl;        
  }
}