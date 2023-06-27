#include "src/lion.h"

#include <iostream>

Lion::Lion(const std::string& name) : Animal(name) {}

void Lion::makeSound() const {
    std::cout << name << " says: Roar!" << std::endl;
}