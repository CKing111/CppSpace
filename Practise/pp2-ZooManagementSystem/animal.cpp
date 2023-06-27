#include "src/animal.h"

Animal::Animal(const std::string& name) : name(name) {}

std::string Animal::getName() const { return name; }