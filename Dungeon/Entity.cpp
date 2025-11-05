#include "Entity.h"
#include <iostream>
#include <utility>

// Constructor for Entity – defines a character with a name, max life, and damage
Entity::Entity(std::string name, int maxLife, int damage )
    : name(std::move(name)), maxLife(maxLife),currLife(maxLife), damage(damage) {}

// Copy constructor – creates a copy of another Entity
Entity::Entity(const Entity &other)
    : name(other.name),maxLife(other.maxLife),currLife(other.currLife),damage(other.damage) {}

// Destructor – no additional cleanup needed for now
Entity::~Entity() {}

// Operator << – prints the name, current life, max life, and damage of the character
std :: ostream &operator<<(std::ostream &os, const Entity &e) {
    os << e.getName() << " (" << e.currLife << "/" << e.maxLife << ") - " << e.damage ;
    return os;
}

// Operator += – adds life to the character. If it exceeds max life, it’s limited to the max value.
Entity &Entity::operator+=(const int life) {
    currLife += life;
    if (currLife > maxLife) {
        currLife = maxLife;
    }
    return *this;
}
// Operator -= – subtracts damage from the character
Entity &Entity::operator-=(const int damage) {
    this->damage -= damage;
    return *this;
}


// Operator == – compares two Entities for equality (based on life and damage)
bool Entity::operator==(const Entity &other) const {
    return (currLife * damage) == (other.currLife * other.damage);
}

// Operator > – compares one Entity to another based on life and damage
bool Entity::operator>(const Entity &other) const {
    return (currLife * damage) > (other.currLife * other.damage);
}

// Getter functions – return the values for max life, current life, and damage
int Entity::getMaxLife() const {
    return maxLife;
}

int Entity::getCurrLife() const  {
    return currLife;
}

void Entity::setLife(int life) {
    this->currLife = life;
}


// Assignment operator – copies the values of one Entity to another
Entity& Entity::operator=(const Entity &other) {
    if (this != &other) { // Check if it’s not self-assignment
        return *this ;
    }
    name = other.name;
    maxLife = other.maxLife;
    currLife = other.currLife;
    damage = other.damage;
    return *this;
}
