#include "src/elephant.h"

#include <iostream>
/**
 * @brief Construct a new Elephant:: Elephant object
 * 
 * @param name 
 */
Elephant::Elephant(const std::string& name) : Animal(name) {}

void Elephant::makeSound() const {
    std::cout << name << " says: Trumpet!" << std::endl;
}