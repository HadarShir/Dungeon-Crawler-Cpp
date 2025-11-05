
#include "Sorcerer.h"

// Constructor: Initializes the sorcerer with its name, max life, and damage values.
Sorcerer::Sorcerer(std::string name, int maxLife, int damage)
    :Player(std::move(name), maxLife, damage){}

// Checks if the sorcerer can activate their special ability based on the turn counter.
bool Sorcerer::CanUseSpecial()  {
    if (turnCounter == 0) return canActivate=true;
    if (turnCounter > 4) {
        canActivate = true;
        turnCounter=0;
    } else canActivate = false;
    return canActivate;
}

// Returns the name of the sorcerer (for display purposes).
std::string Sorcerer::getName() const {
    return "Sorcerer";
}

// Calculates the damage dealt to a monster.
int Sorcerer::getDamage(Entity &monster) const {
    return damage;
}

// Operator -= – subtracts damage from another Entity ( another character's damage reduces the current character's life)
Entity & Sorcerer::operator-=(Entity &other) {
    currLife-=other.getDamage(*this);
    return *this;
}

Sorcerer::~Sorcerer() = default;
