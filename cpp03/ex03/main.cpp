#include "DiamondTrap.hpp"

int main() {
    DiamondTrap dt("Diamond");
    std::cout << "Testing whoAmI:" << std::endl;
    dt.whoAmI();

    std::cout << "\nTesting attack:" << std::endl;
    dt.attack("ds");

    std::cout << "\nTesting displayStats:" << std::endl;
    dt.displayStats();

    return 0;
}