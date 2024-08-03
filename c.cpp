#include <iostream>
#include <string>

// Weapon class definition
class Weapon {
public:
    Weapon(const std::string& type) : type(type) {
        std::cout << "Weapon created: " << type << std::endl;
    }
    ~Weapon() {
        std::cout << "Weapon destroyed: " << type << std::endl;
    }
    const std::string& getType() const { return type; }
    void setType(const std::string& newType) { type = newType; }

private:
    std::string type;
};

// HumanA class definition
class HumanA {
public:
    HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {
        std::cout << "HumanA created: " << name << std::endl;
    }
    ~HumanA() {
        std::cout << "HumanA destroyed: " << name << std::endl;
    }
    void attack() const {
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    }

private:
    std::string name;
    Weapon& weapon; // Reference to Weapon
};

// HumanB class definition
class HumanB {
public:
    HumanB(const std::string& name) : name(name), weapon(NULL) {
        std::cout << "HumanB created: " << name << std::endl;
    }
    ~HumanB() {
        std::cout << "HumanB destroyed: " << name << std::endl;
    }
    void setWeapon(Weapon& weapon) { 
        this->weapon = &weapon; 
        std::cout << name << " is now armed with " << weapon.getType() << std::endl;
    }
    void attack() const {
        if (weapon) {
            std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        } else {
            std::cout << name << " has no weapon to attack with." << std::endl;
        }
    }

private:
    std::string name;
    Weapon* weapon; // Pointer to Weapon
};

// Main function to test the classes
int main() {
    std::cout << "=== Test HumanA ===" << std::endl;
    {
        Weapon club("crude spiked club"); // Static allocation
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    
    std::cout << "=== Test HumanB ===" << std::endl;
    {
        Weapon club("crude spiked club"); // Static allocation
        HumanB jim("Jim");
        jim.setWeapon(club); // Jim now has a reference to the statically allocated weapon
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}