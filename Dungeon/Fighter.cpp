#include "Fighter.h"
#include <iostream>

// Constructor: Initializes the fighter with its name, max life, and damage values.
Fighter::Fighter(std::string name, int maxLife, int damage)
    :Player(std::move(name), maxLife, damage){}

// Returns the name of the fighter.
std::string Fighter::getName() const {
    return "Fighter";
}

// Calculates the damage dealt to a monster.
int Fighter::getDamage(Entity &monster) const {
    return damage;
}

// Overloaded operator to handle interaction with another entity.
Entity & Fighter::operator-=(Entity &other) {
    // We will check if the player has a special ability to use
    if (this->CanUseSpecial()) {
        return *this;
    }
    currLife-= other.getDamage(*this);
    return *this;
}
// Checks if the fighter's special ability can be activated based on the turn counter.
bool Fighter::CanUseSpecial()  {
    if (turnCounter == 0) return canActivate=true;
    if (turnCounter >= 4) {
        canActivate = true;
        turnCounter=0;
    } else canActivate = false;
    return canActivate;
}

Fighter::~Fighter() = default;
