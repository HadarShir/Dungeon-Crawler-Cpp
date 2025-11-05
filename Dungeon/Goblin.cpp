

#include "Goblin.h"
#include <cmath>
// Constructor: Initializes the goblin with its name, maximum life, and damage values.
Goblin::Goblin(std::string name, int maxLife, int damage)
    :Monster(std::move(name), maxLife, damage){}

// Returns the name of the goblin.
std::string Goblin::getName() const {
    return "Goblin";
}


// Operator -= – subtracts damage from another Entity ( another character's damage reduces the current character's life)
Entity & Goblin::operator-=(Entity &other) {
     Player* playerPtr = dynamic_cast<Player*>(&other);
    if (playerPtr) {
        // We will convert the character into a player type knowing that in a monster game you always fight against a player
        if (playerPtr->CanUseSpecial()) {
            // We will check if the player in front of us has a special ability to use against us
            int temp = playerPtr->getSpecialDamage();
            if (temp != 0) {
                this->currLife -= temp;
                return *this;
            }
        }
    }
    this->currLife-= other.getDamage(*this);

    return *this;
}

// Calculate damage
int Goblin::getDamage(Entity &entity) const {
    // We will convert the character into a player type knowing that in a monster game you always fight against a player
    const Player* playerPtr = dynamic_cast<Player*>(&entity);
    if (playerPtr) {
        double res =  this->damage * playerPtr->getDamageModeGoblin() ;
        return static_cast<int>(std::round(res));
    }
    return this->damage;
}


Goblin::~Goblin() = default;